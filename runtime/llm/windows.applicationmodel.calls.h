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
#ifndef LLM_OS_ApplicationModel_Calls_H
#define LLM_OS_ApplicationModel_Calls_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.h"
#include "llm/impl/Windows.ApplicationModel.Contacts.2.h"
#include "llm/impl/Windows.Devices.Enumeration.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.ApplicationModel.Calls.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia) consume_Windows_ApplicationModel_Calls_ICallAnswerEventArgs<D>::AcceptedMedia() const
    {
        llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::ICallAnswerEventArgs)->get_AcceptedMedia(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCallRejectReason) consume_Windows_ApplicationModel_Calls_ICallRejectEventArgs<D>::RejectReason() const
    {
        llm::OS::ApplicationModel::Calls::VoipPhoneCallRejectReason value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::ICallRejectEventArgs)->get_RejectReason(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCallState) consume_Windows_ApplicationModel_Calls_ICallStateChangeEventArgs<D>::State() const
    {
        llm::OS::ApplicationModel::Calls::VoipPhoneCallState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::ICallStateChangeEventArgs)->get_State(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_ILockScreenCallEndCallDeferral<D>::Complete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::ILockScreenCallEndCallDeferral)->Complete());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::LockScreenCallEndCallDeferral) consume_Windows_ApplicationModel_Calls_ILockScreenCallEndRequestedEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs)->GetDeferral(&value));
        return llm::OS::ApplicationModel::Calls::LockScreenCallEndCallDeferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_ApplicationModel_Calls_ILockScreenCallEndRequestedEventArgs<D>::Deadline() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs)->get_Deadline(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_ILockScreenCallUI<D>::Dismiss() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::ILockScreenCallUI)->Dismiss());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_ILockScreenCallUI<D>::EndRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::LockScreenCallUI, llm::OS::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::ILockScreenCallUI)->add_EndRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_ILockScreenCallUI<D>::EndRequested_revoker consume_Windows_ApplicationModel_Calls_ILockScreenCallUI<D>::EndRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::LockScreenCallUI, llm::OS::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, EndRequested_revoker>(this, EndRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_ILockScreenCallUI<D>::EndRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::ILockScreenCallUI)->remove_EndRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_ILockScreenCallUI<D>::Closed(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::LockScreenCallUI, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::ILockScreenCallUI)->add_Closed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_ILockScreenCallUI<D>::Closed_revoker consume_Windows_ApplicationModel_Calls_ILockScreenCallUI<D>::Closed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::LockScreenCallUI, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Closed_revoker>(this, Closed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_ILockScreenCallUI<D>::Closed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::ILockScreenCallUI)->remove_Closed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_ILockScreenCallUI<D>::CallTitle() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::ILockScreenCallUI)->get_CallTitle(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_ILockScreenCallUI<D>::CallTitle(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::ILockScreenCallUI)->put_CallTitle(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IMuteChangeEventArgs<D>::Muted() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IMuteChangeEventArgs)->get_Muted(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::StatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneCall, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->add_StatusChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::StatusChanged_revoker consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::StatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneCall, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, StatusChanged_revoker>(this, StatusChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::StatusChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->remove_StatusChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::AudioDeviceChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneCall, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->add_AudioDeviceChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::AudioDeviceChanged_revoker consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::AudioDeviceChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneCall, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, AudioDeviceChanged_revoker>(this, AudioDeviceChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::AudioDeviceChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->remove_AudioDeviceChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::IsMutedChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneCall, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->add_IsMutedChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::IsMutedChanged_revoker consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::IsMutedChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneCall, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, IsMutedChanged_revoker>(this, IsMutedChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::IsMutedChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->remove_IsMutedChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::CallId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->get_CallId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::IsMuted() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->get_IsMuted(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallStatus) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::Status() const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallAudioDevice) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::AudioDevice() const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallAudioDevice value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->get_AudioDevice(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallInfo) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::GetPhoneCallInfo() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->GetPhoneCallInfo(&result));
        return llm::OS::ApplicationModel::Calls::PhoneCallInfo{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallInfo>) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::GetPhoneCallInfoAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->GetPhoneCallInfoAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallInfo>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::End() const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->End(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::EndAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->EndAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::SendDtmfKey(llm::OS::ApplicationModel::Calls::DtmfKey const& key, llm::OS::ApplicationModel::Calls::DtmfToneAudioPlayback const& dtmfToneAudioPlayback) const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->SendDtmfKey(static_cast<int32_t>(key), static_cast<int32_t>(dtmfToneAudioPlayback), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::SendDtmfKeyAsync(llm::OS::ApplicationModel::Calls::DtmfKey const& key, llm::OS::ApplicationModel::Calls::DtmfToneAudioPlayback const& dtmfToneAudioPlayback) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->SendDtmfKeyAsync(static_cast<int32_t>(key), static_cast<int32_t>(dtmfToneAudioPlayback), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::AcceptIncoming() const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->AcceptIncoming(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::AcceptIncomingAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->AcceptIncomingAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::Hold() const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->Hold(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::HoldAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->HoldAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::ResumeFromHold() const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->ResumeFromHold(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::ResumeFromHoldAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->ResumeFromHoldAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::Mute() const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->Mute(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::MuteAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->MuteAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::Unmute() const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->Unmute(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::UnmuteAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->UnmuteAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::RejectIncoming() const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->RejectIncoming(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::RejectIncomingAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->RejectIncomingAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::ChangeAudioDevice(llm::OS::ApplicationModel::Calls::PhoneCallAudioDevice const& endpoint) const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->ChangeAudioDevice(static_cast<int32_t>(endpoint), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) consume_Windows_ApplicationModel_Calls_IPhoneCall<D>::ChangeAudioDeviceAsync(llm::OS::ApplicationModel::Calls::PhoneCallAudioDevice const& endpoint) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCall)->ChangeAudioDeviceAsync(static_cast<int32_t>(endpoint), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneCallBlockingStatics<D>::BlockUnknownNumbers() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallBlockingStatics)->get_BlockUnknownNumbers(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallBlockingStatics<D>::BlockUnknownNumbers(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallBlockingStatics)->put_BlockUnknownNumbers(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneCallBlockingStatics<D>::BlockPrivateNumbers() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallBlockingStatics)->get_BlockPrivateNumbers(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallBlockingStatics<D>::BlockPrivateNumbers(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallBlockingStatics)->put_BlockPrivateNumbers(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_ApplicationModel_Calls_IPhoneCallBlockingStatics<D>::SetCallBlockingListAsync(param::async_iterable<hstring> const& phoneNumberList) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallBlockingStatics)->SetCallBlockingListAsync(*(void**)(&phoneNumberList), &result));
        return llm::OS::Foundation::IAsyncOperation<bool>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryAddress) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::Address() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_Address(&value));
        return llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryAddress{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::Address(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryAddress const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->put_Address(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::Duration() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_Duration(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::Duration(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->put_Duration(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::IsCallerIdBlocked() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_IsCallerIdBlocked(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::IsCallerIdBlocked(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->put_IsCallerIdBlocked(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::IsEmergency() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_IsEmergency(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::IsEmergency(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->put_IsEmergency(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::IsIncoming() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_IsIncoming(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::IsIncoming(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->put_IsIncoming(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::IsMissed() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_IsMissed(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::IsMissed(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->put_IsMissed(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::IsRinging() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_IsRinging(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::IsRinging(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->put_IsRinging(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::IsSeen() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_IsSeen(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::IsSeen(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->put_IsSeen(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::IsSuppressed() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_IsSuppressed(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::IsSuppressed(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->put_IsSuppressed(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::IsVoicemail() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_IsVoicemail(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::IsVoicemail(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->put_IsVoicemail(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryMedia) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::Media() const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryMedia value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_Media(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::Media(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryMedia const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->put_Media(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::OtherAppReadAccess() const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_OtherAppReadAccess(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::OtherAppReadAccess(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->put_OtherAppReadAccess(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::RemoteId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_RemoteId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::RemoteId(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->put_RemoteId(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::SourceDisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_SourceDisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::SourceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_SourceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::SourceId(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->put_SourceId(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistorySourceIdKind) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::SourceIdKind() const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallHistorySourceIdKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_SourceIdKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::SourceIdKind(llm::OS::ApplicationModel::Calls::PhoneCallHistorySourceIdKind const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->put_SourceIdKind(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::StartTime() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->get_StartTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>::StartTime(llm::OS::Foundation::DateTime const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry)->put_StartTime(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryAddress<D>::ContactId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress)->get_ContactId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryAddress<D>::ContactId(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress)->put_ContactId(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryAddress<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryAddress<D>::DisplayName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress)->put_DisplayName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryAddress<D>::RawAddress() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress)->get_RawAddress(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryAddress<D>::RawAddress(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress)->put_RawAddress(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryAddress<D>::RawAddressKind() const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress)->get_RawAddressKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryAddress<D>::RawAddressKind(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress)->put_RawAddressKind(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryAddress) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryAddressFactory<D>::Create(param::hstring const& rawAddress, llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind const& rawAddressKind) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory)->Create(*(void**)(&rawAddress), static_cast<int32_t>(rawAddressKind), &result));
        return llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryAddress{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryQueryOptions<D>::DesiredMedia() const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions)->get_DesiredMedia(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryQueryOptions<D>::DesiredMedia(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions)->put_DesiredMedia(static_cast<uint32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryQueryOptions<D>::SourceIds() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions)->get_SourceIds(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry>>) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryReader<D>::ReadBatchAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryReader)->ReadBatchAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry>>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallHistoryStore>) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryManagerForUser<D>::RequestStoreAsync(llm::OS::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType const& accessType) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser)->RequestStoreAsync(static_cast<int32_t>(accessType), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallHistoryStore>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryManagerForUser<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallHistoryStore>) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryManagerStatics<D>::RequestStoreAsync(llm::OS::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType const& accessType) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics)->RequestStoreAsync(static_cast<int32_t>(accessType), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallHistoryStore>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryManagerForUser) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryManagerStatics2<D>::GetForUser(llm::OS::System::User const& user) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2)->GetForUser(*(void**)(&user), &result));
        return llm::OS::ApplicationModel::Calls::PhoneCallHistoryManagerForUser{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry>) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryStore<D>::GetEntryAsync(param::hstring const& callHistoryEntryId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore)->GetEntryAsync(*(void**)(&callHistoryEntryId), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryReader) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryStore<D>::GetEntryReader() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore)->GetEntryReader(&result));
        return llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryReader{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryReader) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryStore<D>::GetEntryReader(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions const& queryOptions) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore)->GetEntryReaderWithOptions(*(void**)(&queryOptions), &result));
        return llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryReader{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryStore<D>::SaveEntryAsync(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry const& callHistoryEntry) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore)->SaveEntryAsync(*(void**)(&callHistoryEntry), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryStore<D>::DeleteEntryAsync(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry const& callHistoryEntry) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore)->DeleteEntryAsync(*(void**)(&callHistoryEntry), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryStore<D>::DeleteEntriesAsync(param::async_iterable<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry> const& callHistoryEntries) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore)->DeleteEntriesAsync(*(void**)(&callHistoryEntries), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryStore<D>::MarkEntryAsSeenAsync(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry const& callHistoryEntry) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore)->MarkEntryAsSeenAsync(*(void**)(&callHistoryEntry), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryStore<D>::MarkEntriesAsSeenAsync(param::async_iterable<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry> const& callHistoryEntries) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore)->MarkEntriesAsSeenAsync(*(void**)(&callHistoryEntries), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<uint32_t>) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryStore<D>::GetUnseenCountAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore)->GetUnseenCountAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<uint32_t>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryStore<D>::MarkAllAsSeenAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore)->MarkAllAsSeenAsync(&result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<uint32_t>) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryStore<D>::GetSourcesUnseenCountAsync(param::async_iterable<hstring> const& sourceIds) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore)->GetSourcesUnseenCountAsync(*(void**)(&sourceIds), &result));
        return llm::OS::Foundation::IAsyncOperation<uint32_t>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryStore<D>::MarkSourcesAsSeenAsync(param::async_iterable<hstring> const& sourceIds) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore)->MarkSourcesAsSeenAsync(*(void**)(&sourceIds), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_Calls_IPhoneCallInfo<D>::LineId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallInfo)->get_LineId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneCallInfo<D>::IsHoldSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallInfo)->get_IsHoldSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_ApplicationModel_Calls_IPhoneCallInfo<D>::StartTime() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallInfo)->get_StartTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneCallInfo<D>::PhoneNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallInfo)->get_PhoneNumber(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneCallInfo<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallInfo)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallDirection) consume_Windows_ApplicationModel_Calls_IPhoneCallInfo<D>::CallDirection() const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallDirection value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallInfo)->get_CallDirection(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallManagerStatics<D>::ShowPhoneCallUI(param::hstring const& phoneNumber, param::hstring const& displayName) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics)->ShowPhoneCallUI(*(void**)(&phoneNumber), *(void**)(&displayName)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IPhoneCallManagerStatics2<D>::CallStateChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2)->add_CallStateChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IPhoneCallManagerStatics2<D>::CallStateChanged_revoker consume_Windows_ApplicationModel_Calls_IPhoneCallManagerStatics2<D>::CallStateChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, CallStateChanged_revoker>(this, CallStateChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallManagerStatics2<D>::CallStateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2)->remove_CallStateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneCallManagerStatics2<D>::IsCallActive() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2)->get_IsCallActive(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneCallManagerStatics2<D>::IsCallIncoming() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2)->get_IsCallIncoming(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneCallManagerStatics2<D>::ShowPhoneCallSettingsUI() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2)->ShowPhoneCallSettingsUI());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallStore>) consume_Windows_ApplicationModel_Calls_IPhoneCallManagerStatics2<D>::RequestStoreAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2)->RequestStoreAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallStore>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCall) consume_Windows_ApplicationModel_Calls_IPhoneCallStatics<D>::GetFromId(param::hstring const& callId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallStatics)->GetFromId(*(void**)(&callId), &result));
        return llm::OS::ApplicationModel::Calls::PhoneCall{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_ApplicationModel_Calls_IPhoneCallStore<D>::IsEmergencyPhoneNumberAsync(param::hstring const& number) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallStore)->IsEmergencyPhoneNumberAsync(*(void**)(&number), &result));
        return llm::OS::Foundation::IAsyncOperation<bool>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::guid>) consume_Windows_ApplicationModel_Calls_IPhoneCallStore<D>::GetDefaultLineAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallStore)->GetDefaultLineAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::guid>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineWatcher) consume_Windows_ApplicationModel_Calls_IPhoneCallStore<D>::RequestLineWatcher() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallStore)->RequestLineWatcher(&result));
        return llm::OS::ApplicationModel::Calls::PhoneLineWatcher{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneCallVideoCapabilities<D>::IsVideoCallingCapable() const
    {
        bool pValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilities)->get_IsVideoCallingCapable(&pValue));
        return pValue;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallVideoCapabilities>) consume_Windows_ApplicationModel_Calls_IPhoneCallVideoCapabilitiesManagerStatics<D>::GetCapabilitiesAsync(param::hstring const& phoneNumber) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilitiesManagerStatics)->GetCapabilitiesAsync(*(void**)(&phoneNumber), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallVideoCapabilities>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineOperationStatus) consume_Windows_ApplicationModel_Calls_IPhoneCallsResult<D>::OperationStatus() const
    {
        llm::OS::ApplicationModel::Calls::PhoneLineOperationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallsResult)->get_OperationStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Calls::PhoneCall>) consume_Windows_ApplicationModel_Calls_IPhoneCallsResult<D>::AllActivePhoneCalls() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneCallsResult)->get_AllActivePhoneCalls(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Calls::PhoneCall>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneDialOptions<D>::Number() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneDialOptions)->get_Number(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneDialOptions<D>::Number(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneDialOptions)->put_Number(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneDialOptions<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneDialOptions)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneDialOptions<D>::DisplayName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneDialOptions)->put_DisplayName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::Contact) consume_Windows_ApplicationModel_Calls_IPhoneDialOptions<D>::Contact() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneDialOptions)->get_Contact(&value));
        return llm::OS::ApplicationModel::Contacts::Contact{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneDialOptions<D>::Contact(llm::OS::ApplicationModel::Contacts::Contact const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneDialOptions)->put_Contact(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactPhone) consume_Windows_ApplicationModel_Calls_IPhoneDialOptions<D>::ContactPhone() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneDialOptions)->get_ContactPhone(&value));
        return llm::OS::ApplicationModel::Contacts::ContactPhone{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneDialOptions<D>::ContactPhone(llm::OS::ApplicationModel::Contacts::ContactPhone const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneDialOptions)->put_ContactPhone(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallMedia) consume_Windows_ApplicationModel_Calls_IPhoneDialOptions<D>::Media() const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallMedia value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneDialOptions)->get_Media(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneDialOptions<D>::Media(llm::OS::ApplicationModel::Calls::PhoneCallMedia const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneDialOptions)->put_Media(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneAudioRoutingEndpoint) consume_Windows_ApplicationModel_Calls_IPhoneDialOptions<D>::AudioEndpoint() const
    {
        llm::OS::ApplicationModel::Calls::PhoneAudioRoutingEndpoint value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneDialOptions)->get_AudioEndpoint(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneDialOptions<D>::AudioEndpoint(llm::OS::ApplicationModel::Calls::PhoneAudioRoutingEndpoint const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneDialOptions)->put_AudioEndpoint(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::LineChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLine, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine)->add_LineChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::LineChanged_revoker consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::LineChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLine, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, LineChanged_revoker>(this, LineChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::LineChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine)->remove_LineChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::Id() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine)->get_Id(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::DisplayColor() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine)->get_DisplayColor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneNetworkState) consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::NetworkState() const
    {
        llm::OS::ApplicationModel::Calls::PhoneNetworkState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine)->get_NetworkState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneVoicemail) consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::Voicemail() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine)->get_Voicemail(&value));
        return llm::OS::ApplicationModel::Calls::PhoneVoicemail{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::NetworkName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine)->get_NetworkName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineCellularDetails) consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::CellularDetails() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine)->get_CellularDetails(&value));
        return llm::OS::ApplicationModel::Calls::PhoneLineCellularDetails{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineTransport) consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::Transport() const
    {
        llm::OS::ApplicationModel::Calls::PhoneLineTransport value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine)->get_Transport(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::CanDial() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine)->get_CanDial(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::SupportsTile() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine)->get_SupportsTile(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallVideoCapabilities) consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::VideoCallingCapabilities() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine)->get_VideoCallingCapabilities(&value));
        return llm::OS::ApplicationModel::Calls::PhoneCallVideoCapabilities{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineConfiguration) consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::LineConfiguration() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine)->get_LineConfiguration(&value));
        return llm::OS::ApplicationModel::Calls::PhoneLineConfiguration{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::IsImmediateDialNumberAsync(param::hstring const& number) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine)->IsImmediateDialNumberAsync(*(void**)(&number), &result));
        return llm::OS::Foundation::IAsyncOperation<bool>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::Dial(param::hstring const& number, param::hstring const& displayName) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine)->Dial(*(void**)(&number), *(void**)(&displayName)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneLine<D>::DialWithOptions(llm::OS::ApplicationModel::Calls::PhoneDialOptions const& options) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine)->DialWithOptions(*(void**)(&options)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneLine2<D>::EnableTextReply(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine2)->EnableTextReply(value));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneLine2<D>::TransportDeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine2)->get_TransportDeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineDialResult) consume_Windows_ApplicationModel_Calls_IPhoneLine3<D>::DialWithResult(param::hstring const& number, param::hstring const& displayName) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine3)->DialWithResult(*(void**)(&number), *(void**)(&displayName), &result));
        return llm::OS::ApplicationModel::Calls::PhoneLineDialResult{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneLineDialResult>) consume_Windows_ApplicationModel_Calls_IPhoneLine3<D>::DialWithResultAsync(param::hstring const& number, param::hstring const& displayName) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine3)->DialWithResultAsync(*(void**)(&number), *(void**)(&displayName), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneLineDialResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallsResult) consume_Windows_ApplicationModel_Calls_IPhoneLine3<D>::GetAllActivePhoneCalls() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine3)->GetAllActivePhoneCalls(&result));
        return llm::OS::ApplicationModel::Calls::PhoneCallsResult{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallsResult>) consume_Windows_ApplicationModel_Calls_IPhoneLine3<D>::GetAllActivePhoneCallsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLine3)->GetAllActivePhoneCallsAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallsResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneSimState) consume_Windows_ApplicationModel_Calls_IPhoneLineCellularDetails<D>::SimState() const
    {
        llm::OS::ApplicationModel::Calls::PhoneSimState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineCellularDetails)->get_SimState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_ApplicationModel_Calls_IPhoneLineCellularDetails<D>::SimSlotIndex() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineCellularDetails)->get_SimSlotIndex(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneLineCellularDetails<D>::IsModemOn() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineCellularDetails)->get_IsModemOn(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_ApplicationModel_Calls_IPhoneLineCellularDetails<D>::RegistrationRejectCode() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineCellularDetails)->get_RegistrationRejectCode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneLineCellularDetails<D>::GetNetworkOperatorDisplayText(llm::OS::ApplicationModel::Calls::PhoneLineNetworkOperatorDisplayTextLocation const& location) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineCellularDetails)->GetNetworkOperatorDisplayText(static_cast<int32_t>(location), &value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneLineConfiguration<D>::IsVideoCallingEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineConfiguration)->get_IsVideoCallingEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>) consume_Windows_ApplicationModel_Calls_IPhoneLineConfiguration<D>::ExtendedProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineConfiguration)->get_ExtendedProperties(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) consume_Windows_ApplicationModel_Calls_IPhoneLineDialResult<D>::DialCallStatus() const
    {
        llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineDialResult)->get_DialCallStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCall) consume_Windows_ApplicationModel_Calls_IPhoneLineDialResult<D>::DialedCall() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineDialResult)->get_DialedCall(&value));
        return llm::OS::ApplicationModel::Calls::PhoneCall{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneLine>) consume_Windows_ApplicationModel_Calls_IPhoneLineStatics<D>::FromIdAsync(llm::guid const& lineId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineStatics)->FromIdAsync(impl::bind_in(lineId), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneLine>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineTransport) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice<D>::Transport() const
    {
        llm::OS::ApplicationModel::Calls::PhoneLineTransport value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice)->get_Transport(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceAccessStatus>) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice<D>::RequestAccessAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice)->RequestAccessAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceAccessStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice<D>::RegisterApp() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice)->RegisterApp());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice<D>::RegisterAppForUser(llm::OS::System::User const& user) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice)->RegisterAppForUser(*(void**)(&user)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice<D>::UnregisterApp() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice)->UnregisterApp());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice<D>::UnregisterAppForUser(llm::OS::System::User const& user) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice)->UnregisterAppForUser(*(void**)(&user)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice<D>::IsRegistered() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice)->IsRegistered(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice<D>::Connect() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice)->Connect(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice<D>::ConnectAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice)->ConnectAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::TransportDeviceAudioRoutingStatus) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice2<D>::AudioRoutingStatus() const
    {
        llm::OS::ApplicationModel::Calls::TransportDeviceAudioRoutingStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2)->get_AudioRoutingStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice2<D>::AudioRoutingStatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2)->add_AudioRoutingStatusChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice2<D>::AudioRoutingStatusChanged_revoker consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice2<D>::AudioRoutingStatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, AudioRoutingStatusChanged_revoker>(this, AudioRoutingStatusChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice2<D>::AudioRoutingStatusChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2)->remove_AudioRoutingStatusChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice2<D>::InBandRingingEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2)->get_InBandRingingEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice2<D>::InBandRingingEnabledChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2)->add_InBandRingingEnabledChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice2<D>::InBandRingingEnabledChanged_revoker consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice2<D>::InBandRingingEnabledChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, InBandRingingEnabledChanged_revoker>(this, InBandRingingEnabledChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice2<D>::InBandRingingEnabledChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2)->remove_InBandRingingEnabledChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDeviceStatics<D>::FromId(param::hstring const& id) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDeviceStatics)->FromId(*(void**)(&id), &result));
        return llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDeviceStatics<D>::GetDeviceSelector() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDeviceStatics)->GetDeviceSelector(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDeviceStatics<D>::GetDeviceSelector(llm::OS::ApplicationModel::Calls::PhoneLineTransport const& transport) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineTransportDeviceStatics)->GetDeviceSelectorForPhoneLineTransport(static_cast<int32_t>(transport), &result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineWatcher)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineWatcher)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::LineAdded(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineWatcher)->add_LineAdded(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::LineAdded_revoker consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::LineAdded(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, LineAdded_revoker>(this, LineAdded(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::LineAdded(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineWatcher)->remove_LineAdded(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::LineRemoved(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineWatcher)->add_LineRemoved(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::LineRemoved_revoker consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::LineRemoved(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, LineRemoved_revoker>(this, LineRemoved(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::LineRemoved(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineWatcher)->remove_LineRemoved(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::LineUpdated(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineWatcher)->add_LineUpdated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::LineUpdated_revoker consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::LineUpdated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, LineUpdated_revoker>(this, LineUpdated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::LineUpdated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineWatcher)->remove_LineUpdated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::EnumerationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineWatcher)->add_EnumerationCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::EnumerationCompleted_revoker consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::EnumerationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, EnumerationCompleted_revoker>(this, EnumerationCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::EnumerationCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineWatcher)->remove_EnumerationCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::Stopped(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineWatcher)->add_Stopped(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::Stopped_revoker consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::Stopped(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Stopped_revoker>(this, Stopped(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::Stopped(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineWatcher)->remove_Stopped(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineWatcherStatus) consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>::Status() const
    {
        llm::OS::ApplicationModel::Calls::PhoneLineWatcherStatus status{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineWatcher)->get_Status(reinterpret_cast<int32_t*>(&status)));
        return status;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_Calls_IPhoneLineWatcherEventArgs<D>::LineId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneLineWatcherEventArgs)->get_LineId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IPhoneVoicemail<D>::Number() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneVoicemail)->get_Number(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_ApplicationModel_Calls_IPhoneVoicemail<D>::MessageCount() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneVoicemail)->get_MessageCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneVoicemailType) consume_Windows_ApplicationModel_Calls_IPhoneVoicemail<D>::Type() const
    {
        llm::OS::ApplicationModel::Calls::PhoneVoicemailType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneVoicemail)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Calls_IPhoneVoicemail<D>::DialVoicemailAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IPhoneVoicemail)->DialVoicemailAsync(&result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus>) consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator<D>::ReserveCallResourcesAsync(param::hstring const& taskEntryPoint) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipCallCoordinator)->ReserveCallResourcesAsync(*(void**)(&taskEntryPoint), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator<D>::MuteStateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipCallCoordinator, llm::OS::ApplicationModel::Calls::MuteChangeEventArgs> const& muteChangeHandler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipCallCoordinator)->add_MuteStateChanged(*(void**)(&muteChangeHandler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator<D>::MuteStateChanged_revoker consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator<D>::MuteStateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipCallCoordinator, llm::OS::ApplicationModel::Calls::MuteChangeEventArgs> const& muteChangeHandler) const
    {
        return impl::make_event_revoker<D, MuteStateChanged_revoker>(this, MuteStateChanged(muteChangeHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator<D>::MuteStateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipCallCoordinator)->remove_MuteStateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCall) consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator<D>::RequestNewIncomingCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& contactNumber, llm::OS::Foundation::Uri const& contactImage, param::hstring const& serviceName, llm::OS::Foundation::Uri const& brandingImage, param::hstring const& callDetails, llm::OS::Foundation::Uri const& ringtone, llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const& media, llm::OS::Foundation::TimeSpan const& ringTimeout) const
    {
        void* call{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipCallCoordinator)->RequestNewIncomingCall(*(void**)(&context), *(void**)(&contactName), *(void**)(&contactNumber), *(void**)(&contactImage), *(void**)(&serviceName), *(void**)(&brandingImage), *(void**)(&callDetails), *(void**)(&ringtone), static_cast<uint32_t>(media), impl::bind_in(ringTimeout), &call));
        return llm::OS::ApplicationModel::Calls::VoipPhoneCall{ call, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCall) consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator<D>::RequestNewOutgoingCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& serviceName, llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const& media) const
    {
        void* call{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipCallCoordinator)->RequestNewOutgoingCall(*(void**)(&context), *(void**)(&contactName), *(void**)(&serviceName), static_cast<uint32_t>(media), &call));
        return llm::OS::ApplicationModel::Calls::VoipPhoneCall{ call, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator<D>::NotifyMuted() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipCallCoordinator)->NotifyMuted());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator<D>::NotifyUnmuted() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipCallCoordinator)->NotifyUnmuted());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCall) consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator<D>::RequestOutgoingUpgradeToVideoCall(llm::guid const& callUpgradeGuid, param::hstring const& context, param::hstring const& contactName, param::hstring const& serviceName) const
    {
        void* call{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipCallCoordinator)->RequestOutgoingUpgradeToVideoCall(impl::bind_in(callUpgradeGuid), *(void**)(&context), *(void**)(&contactName), *(void**)(&serviceName), &call));
        return llm::OS::ApplicationModel::Calls::VoipPhoneCall{ call, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCall) consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator<D>::RequestIncomingUpgradeToVideoCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& contactNumber, llm::OS::Foundation::Uri const& contactImage, param::hstring const& serviceName, llm::OS::Foundation::Uri const& brandingImage, param::hstring const& callDetails, llm::OS::Foundation::Uri const& ringtone, llm::OS::Foundation::TimeSpan const& ringTimeout) const
    {
        void* call{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipCallCoordinator)->RequestIncomingUpgradeToVideoCall(*(void**)(&context), *(void**)(&contactName), *(void**)(&contactNumber), *(void**)(&contactImage), *(void**)(&serviceName), *(void**)(&brandingImage), *(void**)(&callDetails), *(void**)(&ringtone), impl::bind_in(ringTimeout), &call));
        return llm::OS::ApplicationModel::Calls::VoipPhoneCall{ call, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator<D>::TerminateCellularCall(llm::guid const& callUpgradeGuid) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipCallCoordinator)->TerminateCellularCall(impl::bind_in(callUpgradeGuid)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator<D>::CancelUpgrade(llm::guid const& callUpgradeGuid) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipCallCoordinator)->CancelUpgrade(impl::bind_in(callUpgradeGuid)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCall) consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator2<D>::SetupNewAcceptedCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& contactNumber, param::hstring const& serviceName, llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const& media) const
    {
        void* call{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipCallCoordinator2)->SetupNewAcceptedCall(*(void**)(&context), *(void**)(&contactName), *(void**)(&contactNumber), *(void**)(&serviceName), static_cast<uint32_t>(media), &call));
        return llm::OS::ApplicationModel::Calls::VoipPhoneCall{ call, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCall) consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator3<D>::RequestNewAppInitiatedCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& contactNumber, param::hstring const& serviceName, llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const& media) const
    {
        void* call{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipCallCoordinator3)->RequestNewAppInitiatedCall(*(void**)(&context), *(void**)(&contactName), *(void**)(&contactNumber), *(void**)(&serviceName), static_cast<uint32_t>(media), &call));
        return llm::OS::ApplicationModel::Calls::VoipPhoneCall{ call, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCall) consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator3<D>::RequestNewIncomingCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& contactNumber, llm::OS::Foundation::Uri const& contactImage, param::hstring const& serviceName, llm::OS::Foundation::Uri const& brandingImage, param::hstring const& callDetails, llm::OS::Foundation::Uri const& ringtone, llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const& media, llm::OS::Foundation::TimeSpan const& ringTimeout, param::hstring const& contactRemoteId) const
    {
        void* call{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipCallCoordinator3)->RequestNewIncomingCallWithContactRemoteId(*(void**)(&context), *(void**)(&contactName), *(void**)(&contactNumber), *(void**)(&contactImage), *(void**)(&serviceName), *(void**)(&brandingImage), *(void**)(&callDetails), *(void**)(&ringtone), static_cast<uint32_t>(media), impl::bind_in(ringTimeout), *(void**)(&contactRemoteId), &call));
        return llm::OS::ApplicationModel::Calls::VoipPhoneCall{ call, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus>) consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator4<D>::ReserveCallResourcesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipCallCoordinator4)->ReserveOneProcessCallResourcesAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipCallCoordinator) consume_Windows_ApplicationModel_Calls_IVoipCallCoordinatorStatics<D>::GetDefault() const
    {
        void* coordinator{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipCallCoordinatorStatics)->GetDefault(&coordinator));
        return llm::OS::ApplicationModel::Calls::VoipCallCoordinator{ coordinator, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::EndRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->add_EndRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::EndRequested_revoker consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::EndRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, EndRequested_revoker>(this, EndRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::EndRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->remove_EndRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::HoldRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->add_HoldRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::HoldRequested_revoker consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::HoldRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, HoldRequested_revoker>(this, HoldRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::HoldRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->remove_HoldRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::ResumeRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->add_ResumeRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::ResumeRequested_revoker consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::ResumeRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ResumeRequested_revoker>(this, ResumeRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::ResumeRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->remove_ResumeRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::AnswerRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallAnswerEventArgs> const& acceptHandler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->add_AnswerRequested(*(void**)(&acceptHandler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::AnswerRequested_revoker consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::AnswerRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallAnswerEventArgs> const& acceptHandler) const
    {
        return impl::make_event_revoker<D, AnswerRequested_revoker>(this, AnswerRequested(acceptHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::AnswerRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->remove_AnswerRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::RejectRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallRejectEventArgs> const& rejectHandler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->add_RejectRequested(*(void**)(&rejectHandler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::RejectRequested_revoker consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::RejectRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallRejectEventArgs> const& rejectHandler) const
    {
        return impl::make_event_revoker<D, RejectRequested_revoker>(this, RejectRequested(rejectHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::RejectRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->remove_RejectRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::NotifyCallHeld() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->NotifyCallHeld());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::NotifyCallActive() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->NotifyCallActive());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::NotifyCallEnded() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->NotifyCallEnded());
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::ContactName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->get_ContactName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::ContactName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->put_ContactName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::StartTime() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->get_StartTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::StartTime(llm::OS::Foundation::DateTime const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->put_StartTime(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::CallMedia() const
    {
        llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->get_CallMedia(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::CallMedia(llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->put_CallMedia(static_cast<uint32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>::NotifyCallReady() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall)->NotifyCallReady());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall2<D>::TryShowAppUI() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall2)->TryShowAppUI());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_IVoipPhoneCall3<D>::NotifyCallAccepted(llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const& media) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::IVoipPhoneCall3)->NotifyCallAccepted(static_cast<uint32_t>(media)));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::ICallAnswerEventArgs> : produce_base<D, llm::OS::ApplicationModel::Calls::ICallAnswerEventArgs>
    {
        int32_t __stdcall get_AcceptedMedia(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia>(this->shim().AcceptedMedia());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::ICallRejectEventArgs> : produce_base<D, llm::OS::ApplicationModel::Calls::ICallRejectEventArgs>
    {
        int32_t __stdcall get_RejectReason(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::VoipPhoneCallRejectReason>(this->shim().RejectReason());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::ICallStateChangeEventArgs> : produce_base<D, llm::OS::ApplicationModel::Calls::ICallStateChangeEventArgs>
    {
        int32_t __stdcall get_State(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::VoipPhoneCallState>(this->shim().State());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::ILockScreenCallEndCallDeferral> : produce_base<D, llm::OS::ApplicationModel::Calls::ILockScreenCallEndCallDeferral>
    {
        int32_t __stdcall Complete() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs>
    {
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::LockScreenCallEndCallDeferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Deadline(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Deadline());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::ILockScreenCallUI> : produce_base<D, llm::OS::ApplicationModel::Calls::ILockScreenCallUI>
    {
        int32_t __stdcall Dismiss() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Dismiss();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_EndRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().EndRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::LockScreenCallUI, llm::OS::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EndRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EndRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Closed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Closed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::LockScreenCallUI, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Closed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Closed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_CallTitle(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CallTitle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CallTitle(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CallTitle(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IMuteChangeEventArgs> : produce_base<D, llm::OS::ApplicationModel::Calls::IMuteChangeEventArgs>
    {
        int32_t __stdcall get_Muted(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Muted());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCall> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCall>
    {
        int32_t __stdcall add_StatusChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().StatusChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneCall, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_StatusChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StatusChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_AudioDeviceChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AudioDeviceChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneCall, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AudioDeviceChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioDeviceChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_IsMutedChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().IsMutedChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneCall, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_IsMutedChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsMutedChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_CallId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CallId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsMuted(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsMuted());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AudioDevice(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallAudioDevice>(this->shim().AudioDevice());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPhoneCallInfo(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallInfo>(this->shim().GetPhoneCallInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPhoneCallInfoAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallInfo>>(this->shim().GetPhoneCallInfoAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall End(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>(this->shim().End());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall EndAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>>(this->shim().EndAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendDtmfKey(int32_t key, int32_t dtmfToneAudioPlayback, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>(this->shim().SendDtmfKey(*reinterpret_cast<llm::OS::ApplicationModel::Calls::DtmfKey const*>(&key), *reinterpret_cast<llm::OS::ApplicationModel::Calls::DtmfToneAudioPlayback const*>(&dtmfToneAudioPlayback)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendDtmfKeyAsync(int32_t key, int32_t dtmfToneAudioPlayback, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>>(this->shim().SendDtmfKeyAsync(*reinterpret_cast<llm::OS::ApplicationModel::Calls::DtmfKey const*>(&key), *reinterpret_cast<llm::OS::ApplicationModel::Calls::DtmfToneAudioPlayback const*>(&dtmfToneAudioPlayback)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AcceptIncoming(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>(this->shim().AcceptIncoming());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AcceptIncomingAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>>(this->shim().AcceptIncomingAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Hold(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>(this->shim().Hold());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall HoldAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>>(this->shim().HoldAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ResumeFromHold(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>(this->shim().ResumeFromHold());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ResumeFromHoldAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>>(this->shim().ResumeFromHoldAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Mute(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>(this->shim().Mute());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall MuteAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>>(this->shim().MuteAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Unmute(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>(this->shim().Unmute());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnmuteAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>>(this->shim().UnmuteAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RejectIncoming(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>(this->shim().RejectIncoming());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RejectIncomingAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>>(this->shim().RejectIncomingAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ChangeAudioDevice(int32_t endpoint, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>(this->shim().ChangeAudioDevice(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneCallAudioDevice const*>(&endpoint)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ChangeAudioDeviceAsync(int32_t endpoint, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>>(this->shim().ChangeAudioDeviceAsync(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneCallAudioDevice const*>(&endpoint)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallBlockingStatics> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallBlockingStatics>
    {
        int32_t __stdcall get_BlockUnknownNumbers(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().BlockUnknownNumbers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BlockUnknownNumbers(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BlockUnknownNumbers(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BlockPrivateNumbers(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().BlockPrivateNumbers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BlockPrivateNumbers(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BlockPrivateNumbers(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetCallBlockingListAsync(void* phoneNumberList, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().SetCallBlockingListAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&phoneNumberList)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Address(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryAddress>(this->shim().Address());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Address(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Address(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryAddress const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Duration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().Duration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Duration(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Duration(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsCallerIdBlocked(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCallerIdBlocked());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsCallerIdBlocked(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsCallerIdBlocked(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsEmergency(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEmergency());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsEmergency(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEmergency(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsIncoming(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsIncoming());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsIncoming(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsIncoming(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsMissed(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsMissed());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsMissed(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsMissed(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsRinging(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsRinging());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsRinging(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsRinging(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSeen(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSeen());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsSeen(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsSeen(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSuppressed(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSuppressed());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsSuppressed(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsSuppressed(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsVoicemail(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsVoicemail());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsVoicemail(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsVoicemail(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Media(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryMedia>(this->shim().Media());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Media(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Media(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryMedia const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OtherAppReadAccess(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess>(this->shim().OtherAppReadAccess());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_OtherAppReadAccess(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OtherAppReadAccess(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemoteId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RemoteId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RemoteId(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteId(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourceDisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SourceDisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SourceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SourceId(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceId(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourceIdKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallHistorySourceIdKind>(this->shim().SourceIdKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SourceIdKind(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceIdKind(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneCallHistorySourceIdKind const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StartTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().StartTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StartTime(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartTime(*reinterpret_cast<llm::OS::Foundation::DateTime const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>
    {
        int32_t __stdcall get_ContactId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ContactId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ContactId(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContactId(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DisplayName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RawAddress(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RawAddress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RawAddress(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RawAddress(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RawAddressKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind>(this->shim().RawAddressKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RawAddressKind(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RawAddressKind(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory>
    {
        int32_t __stdcall Create(void* rawAddress, int32_t rawAddressKind, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryAddress>(this->shim().Create(*reinterpret_cast<hstring const*>(&rawAddress), *reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind const*>(&rawAddressKind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions>
    {
        int32_t __stdcall get_DesiredMedia(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia>(this->shim().DesiredMedia());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DesiredMedia(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredMedia(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourceIds(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().SourceIds());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryReader> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryReader>
    {
        int32_t __stdcall ReadBatchAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry>>>(this->shim().ReadBatchAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser>
    {
        int32_t __stdcall RequestStoreAsync(int32_t accessType, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallHistoryStore>>(this->shim().RequestStoreAsync(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType const*>(&accessType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics>
    {
        int32_t __stdcall RequestStoreAsync(int32_t accessType, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallHistoryStore>>(this->shim().RequestStoreAsync(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType const*>(&accessType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2>
    {
        int32_t __stdcall GetForUser(void* user, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallHistoryManagerForUser>(this->shim().GetForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore>
    {
        int32_t __stdcall GetEntryAsync(void* callHistoryEntryId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry>>(this->shim().GetEntryAsync(*reinterpret_cast<hstring const*>(&callHistoryEntryId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetEntryReader(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryReader>(this->shim().GetEntryReader());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetEntryReaderWithOptions(void* queryOptions, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryReader>(this->shim().GetEntryReader(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions const*>(&queryOptions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SaveEntryAsync(void* callHistoryEntry, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SaveEntryAsync(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry const*>(&callHistoryEntry)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeleteEntryAsync(void* callHistoryEntry, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().DeleteEntryAsync(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry const*>(&callHistoryEntry)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeleteEntriesAsync(void* callHistoryEntries, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().DeleteEntriesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry> const*>(&callHistoryEntries)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall MarkEntryAsSeenAsync(void* callHistoryEntry, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().MarkEntryAsSeenAsync(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry const*>(&callHistoryEntry)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall MarkEntriesAsSeenAsync(void* callHistoryEntries, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().MarkEntriesAsSeenAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry> const*>(&callHistoryEntries)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetUnseenCountAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<uint32_t>>(this->shim().GetUnseenCountAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall MarkAllAsSeenAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().MarkAllAsSeenAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSourcesUnseenCountAsync(void* sourceIds, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<uint32_t>>(this->shim().GetSourcesUnseenCountAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&sourceIds)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall MarkSourcesAsSeenAsync(void* sourceIds, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().MarkSourcesAsSeenAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&sourceIds)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallInfo> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallInfo>
    {
        int32_t __stdcall get_LineId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().LineId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsHoldSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsHoldSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StartTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().StartTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhoneNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PhoneNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CallDirection(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallDirection>(this->shim().CallDirection());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics>
    {
        int32_t __stdcall ShowPhoneCallUI(void* phoneNumber, void* displayName) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowPhoneCallUI(*reinterpret_cast<hstring const*>(&phoneNumber), *reinterpret_cast<hstring const*>(&displayName));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2>
    {
        int32_t __stdcall add_CallStateChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().CallStateChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CallStateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CallStateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_IsCallActive(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCallActive());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsCallIncoming(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCallIncoming());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowPhoneCallSettingsUI() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowPhoneCallSettingsUI();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestStoreAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallStore>>(this->shim().RequestStoreAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallStatics> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallStatics>
    {
        int32_t __stdcall GetFromId(void* callId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneCall>(this->shim().GetFromId(*reinterpret_cast<hstring const*>(&callId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallStore> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallStore>
    {
        int32_t __stdcall IsEmergencyPhoneNumberAsync(void* number, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().IsEmergencyPhoneNumberAsync(*reinterpret_cast<hstring const*>(&number)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDefaultLineAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::guid>>(this->shim().GetDefaultLineAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestLineWatcher(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneLineWatcher>(this->shim().RequestLineWatcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilities> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilities>
    {
        int32_t __stdcall get_IsVideoCallingCapable(bool* pValue) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *pValue = detach_from<bool>(this->shim().IsVideoCallingCapable());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilitiesManagerStatics> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilitiesManagerStatics>
    {
        int32_t __stdcall GetCapabilitiesAsync(void* phoneNumber, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallVideoCapabilities>>(this->shim().GetCapabilitiesAsync(*reinterpret_cast<hstring const*>(&phoneNumber)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneCallsResult> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneCallsResult>
    {
        int32_t __stdcall get_OperationStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneLineOperationStatus>(this->shim().OperationStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AllActivePhoneCalls(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Calls::PhoneCall>>(this->shim().AllActivePhoneCalls());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneDialOptions> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneDialOptions>
    {
        int32_t __stdcall get_Number(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Number());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Number(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Number(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DisplayName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Contact(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::Contact>(this->shim().Contact());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Contact(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Contact(*reinterpret_cast<llm::OS::ApplicationModel::Contacts::Contact const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContactPhone(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::ContactPhone>(this->shim().ContactPhone());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ContactPhone(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContactPhone(*reinterpret_cast<llm::OS::ApplicationModel::Contacts::ContactPhone const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Media(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallMedia>(this->shim().Media());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Media(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Media(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneCallMedia const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AudioEndpoint(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneAudioRoutingEndpoint>(this->shim().AudioEndpoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AudioEndpoint(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioEndpoint(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneAudioRoutingEndpoint const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneLine> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneLine>
    {
        int32_t __stdcall add_LineChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().LineChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLine, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_LineChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LineChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Id(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayColor(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().DisplayColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NetworkState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneNetworkState>(this->shim().NetworkState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Voicemail(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneVoicemail>(this->shim().Voicemail());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NetworkName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().NetworkName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CellularDetails(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneLineCellularDetails>(this->shim().CellularDetails());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Transport(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneLineTransport>(this->shim().Transport());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanDial(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanDial());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportsTile(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().SupportsTile());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoCallingCapabilities(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallVideoCapabilities>(this->shim().VideoCallingCapabilities());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LineConfiguration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneLineConfiguration>(this->shim().LineConfiguration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsImmediateDialNumberAsync(void* number, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().IsImmediateDialNumberAsync(*reinterpret_cast<hstring const*>(&number)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Dial(void* number, void* displayName) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Dial(*reinterpret_cast<hstring const*>(&number), *reinterpret_cast<hstring const*>(&displayName));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DialWithOptions(void* options) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DialWithOptions(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneDialOptions const*>(&options));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneLine2> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneLine2>
    {
        int32_t __stdcall EnableTextReply(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnableTextReply(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TransportDeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TransportDeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneLine3> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneLine3>
    {
        int32_t __stdcall DialWithResult(void* number, void* displayName, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneLineDialResult>(this->shim().DialWithResult(*reinterpret_cast<hstring const*>(&number), *reinterpret_cast<hstring const*>(&displayName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DialWithResultAsync(void* number, void* displayName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneLineDialResult>>(this->shim().DialWithResultAsync(*reinterpret_cast<hstring const*>(&number), *reinterpret_cast<hstring const*>(&displayName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAllActivePhoneCalls(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallsResult>(this->shim().GetAllActivePhoneCalls());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAllActivePhoneCallsAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallsResult>>(this->shim().GetAllActivePhoneCallsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneLineCellularDetails> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneLineCellularDetails>
    {
        int32_t __stdcall get_SimState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneSimState>(this->shim().SimState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SimSlotIndex(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().SimSlotIndex());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsModemOn(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsModemOn());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RegistrationRejectCode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().RegistrationRejectCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetNetworkOperatorDisplayText(int32_t location, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetNetworkOperatorDisplayText(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneLineNetworkOperatorDisplayTextLocation const*>(&location)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneLineConfiguration> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneLineConfiguration>
    {
        int32_t __stdcall get_IsVideoCallingEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsVideoCallingEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>(this->shim().ExtendedProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneLineDialResult> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneLineDialResult>
    {
        int32_t __stdcall get_DialCallStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>(this->shim().DialCallStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DialedCall(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneCall>(this->shim().DialedCall());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneLineStatics> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneLineStatics>
    {
        int32_t __stdcall FromIdAsync(llm::guid lineId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneLine>>(this->shim().FromIdAsync(*reinterpret_cast<llm::guid const*>(&lineId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Transport(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneLineTransport>(this->shim().Transport());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAccessAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceAccessStatus>>(this->shim().RequestAccessAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RegisterApp() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterApp();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RegisterAppForUser(void* user) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterAppForUser(*reinterpret_cast<llm::OS::System::User const*>(&user));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnregisterApp() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnregisterApp();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnregisterAppForUser(void* user) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnregisterAppForUser(*reinterpret_cast<llm::OS::System::User const*>(&user));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsRegistered(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsRegistered());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Connect(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().Connect());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ConnectAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().ConnectAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2>
    {
        int32_t __stdcall get_AudioRoutingStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::TransportDeviceAudioRoutingStatus>(this->shim().AudioRoutingStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_AudioRoutingStatusChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AudioRoutingStatusChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AudioRoutingStatusChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioRoutingStatusChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_InBandRingingEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().InBandRingingEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_InBandRingingEnabledChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().InBandRingingEnabledChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_InBandRingingEnabledChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InBandRingingEnabledChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneLineTransportDeviceStatics> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneLineTransportDeviceStatics>
    {
        int32_t __stdcall FromId(void* id, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice>(this->shim().FromId(*reinterpret_cast<hstring const*>(&id)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelector(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelectorForPhoneLineTransport(int32_t transport, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetDeviceSelector(*reinterpret_cast<llm::OS::ApplicationModel::Calls::PhoneLineTransport const*>(&transport)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneLineWatcher> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneLineWatcher>
    {
        int32_t __stdcall Start() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Stop() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_LineAdded(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().LineAdded(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_LineAdded(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LineAdded(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_LineRemoved(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().LineRemoved(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_LineRemoved(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LineRemoved(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_LineUpdated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().LineUpdated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_LineUpdated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LineUpdated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_EnumerationCompleted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().EnumerationCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EnumerationCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Stopped(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Stopped(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Stopped(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Status(int32_t* status) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_from<llm::OS::ApplicationModel::Calls::PhoneLineWatcherStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneLineWatcherEventArgs> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneLineWatcherEventArgs>
    {
        int32_t __stdcall get_LineId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().LineId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IPhoneVoicemail> : produce_base<D, llm::OS::ApplicationModel::Calls::IPhoneVoicemail>
    {
        int32_t __stdcall get_Number(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Number());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MessageCount(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().MessageCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::PhoneVoicemailType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DialVoicemailAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().DialVoicemailAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator> : produce_base<D, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator>
    {
        int32_t __stdcall ReserveCallResourcesAsync(void* taskEntryPoint, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus>>(this->shim().ReserveCallResourcesAsync(*reinterpret_cast<hstring const*>(&taskEntryPoint)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_MuteStateChanged(void* muteChangeHandler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().MuteStateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipCallCoordinator, llm::OS::ApplicationModel::Calls::MuteChangeEventArgs> const*>(&muteChangeHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_MuteStateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MuteStateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall RequestNewIncomingCall(void* context, void* contactName, void* contactNumber, void* contactImage, void* serviceName, void* brandingImage, void* callDetails, void* ringtone, uint32_t media, int64_t ringTimeout, void** call) noexcept final try
        {
            clear_abi(call);
            typename D::abi_guard guard(this->shim());
            *call = detach_from<llm::OS::ApplicationModel::Calls::VoipPhoneCall>(this->shim().RequestNewIncomingCall(*reinterpret_cast<hstring const*>(&context), *reinterpret_cast<hstring const*>(&contactName), *reinterpret_cast<hstring const*>(&contactNumber), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&contactImage), *reinterpret_cast<hstring const*>(&serviceName), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&brandingImage), *reinterpret_cast<hstring const*>(&callDetails), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&ringtone), *reinterpret_cast<llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const*>(&media), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&ringTimeout)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestNewOutgoingCall(void* context, void* contactName, void* serviceName, uint32_t media, void** call) noexcept final try
        {
            clear_abi(call);
            typename D::abi_guard guard(this->shim());
            *call = detach_from<llm::OS::ApplicationModel::Calls::VoipPhoneCall>(this->shim().RequestNewOutgoingCall(*reinterpret_cast<hstring const*>(&context), *reinterpret_cast<hstring const*>(&contactName), *reinterpret_cast<hstring const*>(&serviceName), *reinterpret_cast<llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const*>(&media)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall NotifyMuted() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyMuted();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall NotifyUnmuted() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyUnmuted();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestOutgoingUpgradeToVideoCall(llm::guid callUpgradeGuid, void* context, void* contactName, void* serviceName, void** call) noexcept final try
        {
            clear_abi(call);
            typename D::abi_guard guard(this->shim());
            *call = detach_from<llm::OS::ApplicationModel::Calls::VoipPhoneCall>(this->shim().RequestOutgoingUpgradeToVideoCall(*reinterpret_cast<llm::guid const*>(&callUpgradeGuid), *reinterpret_cast<hstring const*>(&context), *reinterpret_cast<hstring const*>(&contactName), *reinterpret_cast<hstring const*>(&serviceName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestIncomingUpgradeToVideoCall(void* context, void* contactName, void* contactNumber, void* contactImage, void* serviceName, void* brandingImage, void* callDetails, void* ringtone, int64_t ringTimeout, void** call) noexcept final try
        {
            clear_abi(call);
            typename D::abi_guard guard(this->shim());
            *call = detach_from<llm::OS::ApplicationModel::Calls::VoipPhoneCall>(this->shim().RequestIncomingUpgradeToVideoCall(*reinterpret_cast<hstring const*>(&context), *reinterpret_cast<hstring const*>(&contactName), *reinterpret_cast<hstring const*>(&contactNumber), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&contactImage), *reinterpret_cast<hstring const*>(&serviceName), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&brandingImage), *reinterpret_cast<hstring const*>(&callDetails), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&ringtone), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&ringTimeout)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TerminateCellularCall(llm::guid callUpgradeGuid) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TerminateCellularCall(*reinterpret_cast<llm::guid const*>(&callUpgradeGuid));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CancelUpgrade(llm::guid callUpgradeGuid) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CancelUpgrade(*reinterpret_cast<llm::guid const*>(&callUpgradeGuid));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator2> : produce_base<D, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator2>
    {
        int32_t __stdcall SetupNewAcceptedCall(void* context, void* contactName, void* contactNumber, void* serviceName, uint32_t media, void** call) noexcept final try
        {
            clear_abi(call);
            typename D::abi_guard guard(this->shim());
            *call = detach_from<llm::OS::ApplicationModel::Calls::VoipPhoneCall>(this->shim().SetupNewAcceptedCall(*reinterpret_cast<hstring const*>(&context), *reinterpret_cast<hstring const*>(&contactName), *reinterpret_cast<hstring const*>(&contactNumber), *reinterpret_cast<hstring const*>(&serviceName), *reinterpret_cast<llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const*>(&media)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator3> : produce_base<D, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator3>
    {
        int32_t __stdcall RequestNewAppInitiatedCall(void* context, void* contactName, void* contactNumber, void* serviceName, uint32_t media, void** call) noexcept final try
        {
            clear_abi(call);
            typename D::abi_guard guard(this->shim());
            *call = detach_from<llm::OS::ApplicationModel::Calls::VoipPhoneCall>(this->shim().RequestNewAppInitiatedCall(*reinterpret_cast<hstring const*>(&context), *reinterpret_cast<hstring const*>(&contactName), *reinterpret_cast<hstring const*>(&contactNumber), *reinterpret_cast<hstring const*>(&serviceName), *reinterpret_cast<llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const*>(&media)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestNewIncomingCallWithContactRemoteId(void* context, void* contactName, void* contactNumber, void* contactImage, void* serviceName, void* brandingImage, void* callDetails, void* ringtone, uint32_t media, int64_t ringTimeout, void* contactRemoteId, void** call) noexcept final try
        {
            clear_abi(call);
            typename D::abi_guard guard(this->shim());
            *call = detach_from<llm::OS::ApplicationModel::Calls::VoipPhoneCall>(this->shim().RequestNewIncomingCall(*reinterpret_cast<hstring const*>(&context), *reinterpret_cast<hstring const*>(&contactName), *reinterpret_cast<hstring const*>(&contactNumber), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&contactImage), *reinterpret_cast<hstring const*>(&serviceName), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&brandingImage), *reinterpret_cast<hstring const*>(&callDetails), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&ringtone), *reinterpret_cast<llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const*>(&media), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&ringTimeout), *reinterpret_cast<hstring const*>(&contactRemoteId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator4> : produce_base<D, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator4>
    {
        int32_t __stdcall ReserveOneProcessCallResourcesAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus>>(this->shim().ReserveCallResourcesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IVoipCallCoordinatorStatics> : produce_base<D, llm::OS::ApplicationModel::Calls::IVoipCallCoordinatorStatics>
    {
        int32_t __stdcall GetDefault(void** coordinator) noexcept final try
        {
            clear_abi(coordinator);
            typename D::abi_guard guard(this->shim());
            *coordinator = detach_from<llm::OS::ApplicationModel::Calls::VoipCallCoordinator>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IVoipPhoneCall> : produce_base<D, llm::OS::ApplicationModel::Calls::IVoipPhoneCall>
    {
        int32_t __stdcall add_EndRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().EndRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EndRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EndRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_HoldRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().HoldRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_HoldRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HoldRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ResumeRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ResumeRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ResumeRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResumeRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_AnswerRequested(void* acceptHandler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AnswerRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallAnswerEventArgs> const*>(&acceptHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AnswerRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AnswerRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_RejectRequested(void* rejectHandler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RejectRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallRejectEventArgs> const*>(&rejectHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RejectRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RejectRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall NotifyCallHeld() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyCallHeld();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall NotifyCallActive() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyCallActive();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall NotifyCallEnded() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyCallEnded();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContactName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ContactName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ContactName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContactName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StartTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().StartTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StartTime(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartTime(*reinterpret_cast<llm::OS::Foundation::DateTime const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CallMedia(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia>(this->shim().CallMedia());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CallMedia(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CallMedia(*reinterpret_cast<llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall NotifyCallReady() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyCallReady();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IVoipPhoneCall2> : produce_base<D, llm::OS::ApplicationModel::Calls::IVoipPhoneCall2>
    {
        int32_t __stdcall TryShowAppUI() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TryShowAppUI();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::IVoipPhoneCall3> : produce_base<D, llm::OS::ApplicationModel::Calls::IVoipPhoneCall3>
    {
        int32_t __stdcall NotifyCallAccepted(uint32_t media) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyCallAccepted(*reinterpret_cast<llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const*>(&media));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Calls
{
    constexpr auto operator|(PhoneCallHistoryEntryQueryDesiredMedia const left, PhoneCallHistoryEntryQueryDesiredMedia const right) noexcept
    {
        return static_cast<PhoneCallHistoryEntryQueryDesiredMedia>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(PhoneCallHistoryEntryQueryDesiredMedia& left, PhoneCallHistoryEntryQueryDesiredMedia const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(PhoneCallHistoryEntryQueryDesiredMedia const left, PhoneCallHistoryEntryQueryDesiredMedia const right) noexcept
    {
        return static_cast<PhoneCallHistoryEntryQueryDesiredMedia>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(PhoneCallHistoryEntryQueryDesiredMedia& left, PhoneCallHistoryEntryQueryDesiredMedia const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(PhoneCallHistoryEntryQueryDesiredMedia const value) noexcept
    {
        return static_cast<PhoneCallHistoryEntryQueryDesiredMedia>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(PhoneCallHistoryEntryQueryDesiredMedia const left, PhoneCallHistoryEntryQueryDesiredMedia const right) noexcept
    {
        return static_cast<PhoneCallHistoryEntryQueryDesiredMedia>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(PhoneCallHistoryEntryQueryDesiredMedia& left, PhoneCallHistoryEntryQueryDesiredMedia const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    constexpr auto operator|(VoipPhoneCallMedia const left, VoipPhoneCallMedia const right) noexcept
    {
        return static_cast<VoipPhoneCallMedia>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(VoipPhoneCallMedia& left, VoipPhoneCallMedia const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(VoipPhoneCallMedia const left, VoipPhoneCallMedia const right) noexcept
    {
        return static_cast<VoipPhoneCallMedia>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(VoipPhoneCallMedia& left, VoipPhoneCallMedia const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(VoipPhoneCallMedia const value) noexcept
    {
        return static_cast<VoipPhoneCallMedia>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(VoipPhoneCallMedia const left, VoipPhoneCallMedia const right) noexcept
    {
        return static_cast<VoipPhoneCallMedia>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(VoipPhoneCallMedia& left, VoipPhoneCallMedia const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto PhoneCall::GetFromId(param::hstring const& callId)
    {
        return impl::call_factory<PhoneCall, IPhoneCallStatics>([&](IPhoneCallStatics const& f) { return f.GetFromId(callId); });
    }
    inline auto PhoneCallBlocking::BlockUnknownNumbers()
    {
        return impl::call_factory_cast<bool(*)(IPhoneCallBlockingStatics const&), PhoneCallBlocking, IPhoneCallBlockingStatics>([](IPhoneCallBlockingStatics const& f) { return f.BlockUnknownNumbers(); });
    }
    inline auto PhoneCallBlocking::BlockUnknownNumbers(bool value)
    {
        impl::call_factory<PhoneCallBlocking, IPhoneCallBlockingStatics>([&](IPhoneCallBlockingStatics const& f) { return f.BlockUnknownNumbers(value); });
    }
    inline auto PhoneCallBlocking::BlockPrivateNumbers()
    {
        return impl::call_factory_cast<bool(*)(IPhoneCallBlockingStatics const&), PhoneCallBlocking, IPhoneCallBlockingStatics>([](IPhoneCallBlockingStatics const& f) { return f.BlockPrivateNumbers(); });
    }
    inline auto PhoneCallBlocking::BlockPrivateNumbers(bool value)
    {
        impl::call_factory<PhoneCallBlocking, IPhoneCallBlockingStatics>([&](IPhoneCallBlockingStatics const& f) { return f.BlockPrivateNumbers(value); });
    }
    inline auto PhoneCallBlocking::SetCallBlockingListAsync(param::async_iterable<hstring> const& phoneNumberList)
    {
        return impl::call_factory<PhoneCallBlocking, IPhoneCallBlockingStatics>([&](IPhoneCallBlockingStatics const& f) { return f.SetCallBlockingListAsync(phoneNumberList); });
    }
    inline PhoneCallHistoryEntry::PhoneCallHistoryEntry() :
        PhoneCallHistoryEntry(impl::call_factory_cast<PhoneCallHistoryEntry(*)(llm::OS::Foundation::IActivationFactory const&), PhoneCallHistoryEntry>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<PhoneCallHistoryEntry>(); }))
    {
    }
    inline PhoneCallHistoryEntryAddress::PhoneCallHistoryEntryAddress() :
        PhoneCallHistoryEntryAddress(impl::call_factory_cast<PhoneCallHistoryEntryAddress(*)(llm::OS::Foundation::IActivationFactory const&), PhoneCallHistoryEntryAddress>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<PhoneCallHistoryEntryAddress>(); }))
    {
    }
    inline PhoneCallHistoryEntryAddress::PhoneCallHistoryEntryAddress(param::hstring const& rawAddress, llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind const& rawAddressKind) :
        PhoneCallHistoryEntryAddress(impl::call_factory<PhoneCallHistoryEntryAddress, IPhoneCallHistoryEntryAddressFactory>([&](IPhoneCallHistoryEntryAddressFactory const& f) { return f.Create(rawAddress, rawAddressKind); }))
    {
    }
    inline PhoneCallHistoryEntryQueryOptions::PhoneCallHistoryEntryQueryOptions() :
        PhoneCallHistoryEntryQueryOptions(impl::call_factory_cast<PhoneCallHistoryEntryQueryOptions(*)(llm::OS::Foundation::IActivationFactory const&), PhoneCallHistoryEntryQueryOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<PhoneCallHistoryEntryQueryOptions>(); }))
    {
    }
    inline auto PhoneCallHistoryManager::RequestStoreAsync(llm::OS::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType const& accessType)
    {
        return impl::call_factory<PhoneCallHistoryManager, IPhoneCallHistoryManagerStatics>([&](IPhoneCallHistoryManagerStatics const& f) { return f.RequestStoreAsync(accessType); });
    }
    inline auto PhoneCallHistoryManager::GetForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<PhoneCallHistoryManager, IPhoneCallHistoryManagerStatics2>([&](IPhoneCallHistoryManagerStatics2 const& f) { return f.GetForUser(user); });
    }
    inline auto PhoneCallManager::ShowPhoneCallUI(param::hstring const& phoneNumber, param::hstring const& displayName)
    {
        impl::call_factory<PhoneCallManager, IPhoneCallManagerStatics>([&](IPhoneCallManagerStatics const& f) { return f.ShowPhoneCallUI(phoneNumber, displayName); });
    }
    inline auto PhoneCallManager::CallStateChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<PhoneCallManager, IPhoneCallManagerStatics2>([&](IPhoneCallManagerStatics2 const& f) { return f.CallStateChanged(handler); });
    }
    inline PhoneCallManager::CallStateChanged_revoker PhoneCallManager::CallStateChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<PhoneCallManager, llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2>();
        return { f, f.CallStateChanged(handler) };
    }
    inline auto PhoneCallManager::CallStateChanged(llm::event_token const& token)
    {
        impl::call_factory<PhoneCallManager, IPhoneCallManagerStatics2>([&](IPhoneCallManagerStatics2 const& f) { return f.CallStateChanged(token); });
    }
    inline auto PhoneCallManager::IsCallActive()
    {
        return impl::call_factory_cast<bool(*)(IPhoneCallManagerStatics2 const&), PhoneCallManager, IPhoneCallManagerStatics2>([](IPhoneCallManagerStatics2 const& f) { return f.IsCallActive(); });
    }
    inline auto PhoneCallManager::IsCallIncoming()
    {
        return impl::call_factory_cast<bool(*)(IPhoneCallManagerStatics2 const&), PhoneCallManager, IPhoneCallManagerStatics2>([](IPhoneCallManagerStatics2 const& f) { return f.IsCallIncoming(); });
    }
    inline auto PhoneCallManager::ShowPhoneCallSettingsUI()
    {
        impl::call_factory_cast<void(*)(IPhoneCallManagerStatics2 const&), PhoneCallManager, IPhoneCallManagerStatics2>([](IPhoneCallManagerStatics2 const& f) { return f.ShowPhoneCallSettingsUI(); });
    }
    inline auto PhoneCallManager::RequestStoreAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallStore>(*)(IPhoneCallManagerStatics2 const&), PhoneCallManager, IPhoneCallManagerStatics2>([](IPhoneCallManagerStatics2 const& f) { return f.RequestStoreAsync(); });
    }
    inline auto PhoneCallVideoCapabilitiesManager::GetCapabilitiesAsync(param::hstring const& phoneNumber)
    {
        return impl::call_factory<PhoneCallVideoCapabilitiesManager, IPhoneCallVideoCapabilitiesManagerStatics>([&](IPhoneCallVideoCapabilitiesManagerStatics const& f) { return f.GetCapabilitiesAsync(phoneNumber); });
    }
    inline PhoneDialOptions::PhoneDialOptions() :
        PhoneDialOptions(impl::call_factory_cast<PhoneDialOptions(*)(llm::OS::Foundation::IActivationFactory const&), PhoneDialOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<PhoneDialOptions>(); }))
    {
    }
    inline auto PhoneLine::FromIdAsync(llm::guid const& lineId)
    {
        return impl::call_factory<PhoneLine, IPhoneLineStatics>([&](IPhoneLineStatics const& f) { return f.FromIdAsync(lineId); });
    }
    inline auto PhoneLineTransportDevice::FromId(param::hstring const& id)
    {
        return impl::call_factory<PhoneLineTransportDevice, IPhoneLineTransportDeviceStatics>([&](IPhoneLineTransportDeviceStatics const& f) { return f.FromId(id); });
    }
    inline auto PhoneLineTransportDevice::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(IPhoneLineTransportDeviceStatics const&), PhoneLineTransportDevice, IPhoneLineTransportDeviceStatics>([](IPhoneLineTransportDeviceStatics const& f) { return f.GetDeviceSelector(); });
    }
    inline auto PhoneLineTransportDevice::GetDeviceSelector(llm::OS::ApplicationModel::Calls::PhoneLineTransport const& transport)
    {
        return impl::call_factory<PhoneLineTransportDevice, IPhoneLineTransportDeviceStatics>([&](IPhoneLineTransportDeviceStatics const& f) { return f.GetDeviceSelector(transport); });
    }
    inline auto VoipCallCoordinator::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::Calls::VoipCallCoordinator(*)(IVoipCallCoordinatorStatics const&), VoipCallCoordinator, IVoipCallCoordinatorStatics>([](IVoipCallCoordinatorStatics const& f) { return f.GetDefault(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::Calls::ICallAnswerEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::ICallRejectEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::ICallStateChangeEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::ILockScreenCallEndCallDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::ILockScreenCallUI> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IMuteChangeEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCall> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallBlockingStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryReader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallStore> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilitiesManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneCallsResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneDialOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneLine> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneLine2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneLine3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneLineCellularDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneLineConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneLineDialResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneLineStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDeviceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneLineWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneLineWatcherEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IPhoneVoicemail> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IVoipCallCoordinatorStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IVoipPhoneCall> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IVoipPhoneCall2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::IVoipPhoneCall3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::CallAnswerEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::CallRejectEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::LockScreenCallEndCallDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::LockScreenCallUI> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::MuteChangeEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneCall> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneCallBlocking> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryAddress> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryReader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneCallHistoryManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneCallHistoryManagerForUser> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneCallHistoryStore> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneCallInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneCallManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneCallStore> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneCallVideoCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneCallVideoCapabilitiesManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneCallsResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneDialOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneLine> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneLineCellularDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneLineConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneLineDialResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneLineWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::PhoneVoicemail> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::VoipCallCoordinator> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::VoipPhoneCall> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
