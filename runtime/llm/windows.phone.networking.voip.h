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
#ifndef LLM_OS_Phone_Networking_Voip_H
#define LLM_OS_Phone_Networking_Voip_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Phone.Networking.Voip.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Phone::Networking::Voip::VoipCallMedia) consume_Windows_Phone_Networking_Voip_ICallAnswerEventArgs<D>::AcceptedMedia() const
    {
        llm::OS::Phone::Networking::Voip::VoipCallMedia value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::ICallAnswerEventArgs)->get_AcceptedMedia(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Phone::Networking::Voip::VoipCallRejectReason) consume_Windows_Phone_Networking_Voip_ICallRejectEventArgs<D>::RejectReason() const
    {
        llm::OS::Phone::Networking::Voip::VoipCallRejectReason value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::ICallRejectEventArgs)->get_RejectReason(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Phone::Networking::Voip::VoipCallState) consume_Windows_Phone_Networking_Voip_ICallStateChangeEventArgs<D>::State() const
    {
        llm::OS::Phone::Networking::Voip::VoipCallState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::ICallStateChangeEventArgs)->get_State(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Phone_Networking_Voip_IMuteChangeEventArgs<D>::Muted() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IMuteChangeEventArgs)->get_Muted(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Phone_Networking_Voip_IQuerySeamlessUpgradeSupportOperation<D>::RemoteId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IQuerySeamlessUpgradeSupportOperation)->get_RemoteId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IQuerySeamlessUpgradeSupportOperation<D>::NotifyCompletion(bool succeeded, llm::OS::Phone::Networking::Voip::SeamlessCallUpgradeSupport const& seamlessCallUpgradeSupport) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IQuerySeamlessUpgradeSupportOperation)->NotifyCompletion(succeeded, static_cast<int32_t>(seamlessCallUpgradeSupport)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Phone_Networking_Voip_IVoipCallCoordinator<D>::MuteRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipCallCoordinator, llm::OS::Phone::Networking::Voip::MuteChangeEventArgs> const& muteChangeHandler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipCallCoordinator)->add_MuteRequested(*(void**)(&muteChangeHandler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Phone_Networking_Voip_IVoipCallCoordinator<D>::MuteRequested_revoker consume_Windows_Phone_Networking_Voip_IVoipCallCoordinator<D>::MuteRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipCallCoordinator, llm::OS::Phone::Networking::Voip::MuteChangeEventArgs> const& muteChangeHandler) const
    {
        return impl::make_event_revoker<D, MuteRequested_revoker>(this, MuteRequested(muteChangeHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipCallCoordinator<D>::MuteRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipCallCoordinator)->remove_MuteRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Phone_Networking_Voip_IVoipCallCoordinator<D>::UnmuteRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipCallCoordinator, llm::OS::Phone::Networking::Voip::MuteChangeEventArgs> const& muteChangeHandler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipCallCoordinator)->add_UnmuteRequested(*(void**)(&muteChangeHandler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Phone_Networking_Voip_IVoipCallCoordinator<D>::UnmuteRequested_revoker consume_Windows_Phone_Networking_Voip_IVoipCallCoordinator<D>::UnmuteRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipCallCoordinator, llm::OS::Phone::Networking::Voip::MuteChangeEventArgs> const& muteChangeHandler) const
    {
        return impl::make_event_revoker<D, UnmuteRequested_revoker>(this, UnmuteRequested(muteChangeHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipCallCoordinator<D>::UnmuteRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipCallCoordinator)->remove_UnmuteRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipCallCoordinator<D>::RequestNewIncomingCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& contactNumber, llm::OS::Foundation::Uri const& contactImage, param::hstring const& serviceName, llm::OS::Foundation::Uri const& brandingImage, param::hstring const& callDetails, llm::OS::Foundation::Uri const& ringtone, llm::OS::Phone::Networking::Voip::VoipCallMedia const& media, llm::OS::Foundation::TimeSpan const& ringTimeout, llm::OS::Phone::Networking::Voip::VoipPhoneCall& call) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipCallCoordinator)->RequestNewIncomingCall(*(void**)(&context), *(void**)(&contactName), *(void**)(&contactNumber), *(void**)(&contactImage), *(void**)(&serviceName), *(void**)(&brandingImage), *(void**)(&callDetails), *(void**)(&ringtone), static_cast<uint32_t>(media), impl::bind_in(ringTimeout), impl::bind_out(call)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipCallCoordinator<D>::RequestNewOutgoingCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& serviceName, llm::OS::Phone::Networking::Voip::VoipCallMedia const& media, llm::OS::Phone::Networking::Voip::VoipPhoneCall& call) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipCallCoordinator)->RequestNewOutgoingCall(*(void**)(&context), *(void**)(&contactName), *(void**)(&serviceName), static_cast<uint32_t>(media), impl::bind_out(call)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipCallCoordinator<D>::NotifyMuted() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipCallCoordinator)->NotifyMuted());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipCallCoordinator<D>::NotifyUnmuted() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipCallCoordinator)->NotifyUnmuted());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipCallCoordinator2<D>::SetupNewAcceptedCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& contactNumber, param::hstring const& serviceName, llm::OS::Phone::Networking::Voip::VoipCallMedia const& media, llm::OS::Phone::Networking::Voip::VoipPhoneCall& call) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipCallCoordinator2)->SetupNewAcceptedCall(*(void**)(&context), *(void**)(&contactName), *(void**)(&contactNumber), *(void**)(&serviceName), static_cast<uint32_t>(media), impl::bind_out(call)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Phone::Networking::Voip::VoipPhoneCall) consume_Windows_Phone_Networking_Voip_IVoipCallCoordinator3<D>::RequestNewIncomingCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& contactNumber, llm::OS::Foundation::Uri const& contactImage, param::hstring const& serviceName, llm::OS::Foundation::Uri const& brandingImage, param::hstring const& callDetails, llm::OS::Foundation::Uri const& ringtone, llm::OS::Phone::Networking::Voip::VoipCallMedia const& media, llm::OS::Foundation::TimeSpan const& ringTimeout, param::hstring const& contactRemoteId) const
    {
        void* call{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipCallCoordinator3)->RequestNewIncomingCallWithContactRemoteId(*(void**)(&context), *(void**)(&contactName), *(void**)(&contactNumber), *(void**)(&contactImage), *(void**)(&serviceName), *(void**)(&brandingImage), *(void**)(&callDetails), *(void**)(&ringtone), static_cast<uint32_t>(media), impl::bind_in(ringTimeout), *(void**)(&contactRemoteId), &call));
        return llm::OS::Phone::Networking::Voip::VoipPhoneCall{ call, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipCallCoordinator3<D>::RequestNewAppInitiatedCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& contactNumber, param::hstring const& serviceName, llm::OS::Phone::Networking::Voip::VoipCallMedia const& media, llm::OS::Phone::Networking::Voip::VoipPhoneCall& call) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipCallCoordinator3)->RequestNewAppInitiatedCall(*(void**)(&context), *(void**)(&contactName), *(void**)(&contactNumber), *(void**)(&serviceName), static_cast<uint32_t>(media), impl::bind_out(call)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Phone::Networking::Voip::VoipCallCoordinator) consume_Windows_Phone_Networking_Voip_IVoipCallCoordinatorStatics<D>::GetDefault() const
    {
        void* coordinator{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipCallCoordinatorStatics)->GetDefault(&coordinator));
        return llm::OS::Phone::Networking::Voip::VoipCallCoordinator{ coordinator, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipCallCoordinatorWithAppDeterminedUpgrade<D>::ConfirmNonSeamlessUpgrade(llm::guid const& callUpgradeGuid) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipCallCoordinatorWithAppDeterminedUpgrade)->ConfirmNonSeamlessUpgrade(impl::bind_in(callUpgradeGuid)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipCallCoordinatorWithAppDeterminedUpgrade<D>::CancelUpgrade(llm::guid const& callUpgradeGuid) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipCallCoordinatorWithAppDeterminedUpgrade)->CancelUpgrade(impl::bind_in(callUpgradeGuid)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipCallCoordinatorWithUpgrade<D>::RequestOutgoingUpgradeToVideoCall(llm::guid const& callUpgradeGuid, param::hstring const& context, param::hstring const& contactName, param::hstring const& serviceName, llm::OS::Phone::Networking::Voip::VoipPhoneCall& call) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipCallCoordinatorWithUpgrade)->RequestOutgoingUpgradeToVideoCall(impl::bind_in(callUpgradeGuid), *(void**)(&context), *(void**)(&contactName), *(void**)(&serviceName), impl::bind_out(call)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipCallCoordinatorWithUpgrade<D>::RequestIncomingUpgradeToVideoCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& contactNumber, llm::OS::Foundation::Uri const& contactImage, param::hstring const& serviceName, llm::OS::Foundation::Uri const& brandingImage, param::hstring const& callDetails, llm::OS::Foundation::Uri const& ringtone, llm::OS::Foundation::TimeSpan const& ringTimeout, llm::OS::Phone::Networking::Voip::VoipPhoneCall& call) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipCallCoordinatorWithUpgrade)->RequestIncomingUpgradeToVideoCall(*(void**)(&context), *(void**)(&contactName), *(void**)(&contactNumber), *(void**)(&contactImage), *(void**)(&serviceName), *(void**)(&brandingImage), *(void**)(&callDetails), *(void**)(&ringtone), impl::bind_in(ringTimeout), impl::bind_out(call)));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Phone_Networking_Voip_IVoipOperation<D>::Id() const
    {
        uint32_t operationId{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipOperation)->get_Id(&operationId));
        return operationId;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Phone::Networking::Voip::VoipOperationType) consume_Windows_Phone_Networking_Voip_IVoipOperation<D>::Type() const
    {
        llm::OS::Phone::Networking::Voip::VoipOperationType operationType{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipOperation)->get_Type(reinterpret_cast<int32_t*>(&operationType)));
        return operationType;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Phone::Networking::Voip::IVoipOperation) consume_Windows_Phone_Networking_Voip_IVoipOperationsManager<D>::GetNextOperation() const
    {
        void* voipOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipOperationsManager)->GetNextOperation(&voipOperation));
        return llm::OS::Phone::Networking::Voip::IVoipOperation{ voipOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::EndRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipPhoneCall, llm::OS::Phone::Networking::Voip::CallStateChangeEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->add_EndRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::EndRequested_revoker consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::EndRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipPhoneCall, llm::OS::Phone::Networking::Voip::CallStateChangeEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, EndRequested_revoker>(this, EndRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::EndRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->remove_EndRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::HoldRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipPhoneCall, llm::OS::Phone::Networking::Voip::CallStateChangeEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->add_HoldRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::HoldRequested_revoker consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::HoldRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipPhoneCall, llm::OS::Phone::Networking::Voip::CallStateChangeEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, HoldRequested_revoker>(this, HoldRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::HoldRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->remove_HoldRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::ResumeRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipPhoneCall, llm::OS::Phone::Networking::Voip::CallStateChangeEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->add_ResumeRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::ResumeRequested_revoker consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::ResumeRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipPhoneCall, llm::OS::Phone::Networking::Voip::CallStateChangeEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ResumeRequested_revoker>(this, ResumeRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::ResumeRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->remove_ResumeRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::AnswerRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipPhoneCall, llm::OS::Phone::Networking::Voip::CallAnswerEventArgs> const& acceptHandler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->add_AnswerRequested(*(void**)(&acceptHandler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::AnswerRequested_revoker consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::AnswerRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipPhoneCall, llm::OS::Phone::Networking::Voip::CallAnswerEventArgs> const& acceptHandler) const
    {
        return impl::make_event_revoker<D, AnswerRequested_revoker>(this, AnswerRequested(acceptHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::AnswerRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->remove_AnswerRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::RejectRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipPhoneCall, llm::OS::Phone::Networking::Voip::CallRejectEventArgs> const& rejectHandler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->add_RejectRequested(*(void**)(&rejectHandler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::RejectRequested_revoker consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::RejectRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipPhoneCall, llm::OS::Phone::Networking::Voip::CallRejectEventArgs> const& rejectHandler) const
    {
        return impl::make_event_revoker<D, RejectRequested_revoker>(this, RejectRequested(rejectHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::RejectRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->remove_RejectRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::NotifyCallHeld() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->NotifyCallHeld());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::NotifyCallActive() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->NotifyCallActive());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::NotifyCallEnded() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->NotifyCallEnded());
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::ContactName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->get_ContactName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::ContactName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->put_ContactName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::StartTime() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->get_StartTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::StartTime(llm::OS::Foundation::DateTime const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->put_StartTime(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Phone::Networking::Voip::VoipCallMedia) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::CallMedia() const
    {
        llm::OS::Phone::Networking::Voip::VoipCallMedia value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->get_CallMedia(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall<D>::CallMedia(llm::OS::Phone::Networking::Voip::VoipCallMedia const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall)->put_CallMedia(static_cast<uint32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall2<D>::TryShowAppUI() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall2)->TryShowAppUI());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipPhoneCall3<D>::NotifyCallAccepted(llm::OS::Phone::Networking::Voip::VoipCallMedia const& media) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCall3)->NotifyCallAccepted(static_cast<uint32_t>(media)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Phone_Networking_Voip_IVoipPhoneCallReady<D>::NotifyCallReady() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Phone::Networking::Voip::IVoipPhoneCallReady)->NotifyCallReady());
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::Networking::Voip::ICallAnswerEventArgs> : produce_base<D, llm::OS::Phone::Networking::Voip::ICallAnswerEventArgs>
    {
        int32_t __stdcall get_AcceptedMedia(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Phone::Networking::Voip::VoipCallMedia>(this->shim().AcceptedMedia());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::Networking::Voip::ICallRejectEventArgs> : produce_base<D, llm::OS::Phone::Networking::Voip::ICallRejectEventArgs>
    {
        int32_t __stdcall get_RejectReason(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Phone::Networking::Voip::VoipCallRejectReason>(this->shim().RejectReason());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::Networking::Voip::ICallStateChangeEventArgs> : produce_base<D, llm::OS::Phone::Networking::Voip::ICallStateChangeEventArgs>
    {
        int32_t __stdcall get_State(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Phone::Networking::Voip::VoipCallState>(this->shim().State());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::Networking::Voip::IMuteChangeEventArgs> : produce_base<D, llm::OS::Phone::Networking::Voip::IMuteChangeEventArgs>
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
    struct produce<D, llm::OS::Phone::Networking::Voip::IQuerySeamlessUpgradeSupportOperation> : produce_base<D, llm::OS::Phone::Networking::Voip::IQuerySeamlessUpgradeSupportOperation>
    {
        int32_t __stdcall get_RemoteId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RemoteId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall NotifyCompletion(bool succeeded, int32_t seamlessCallUpgradeSupport) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyCompletion(succeeded, *reinterpret_cast<llm::OS::Phone::Networking::Voip::SeamlessCallUpgradeSupport const*>(&seamlessCallUpgradeSupport));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::Networking::Voip::IVoipCallCoordinator> : produce_base<D, llm::OS::Phone::Networking::Voip::IVoipCallCoordinator>
    {
        int32_t __stdcall add_MuteRequested(void* muteChangeHandler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().MuteRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipCallCoordinator, llm::OS::Phone::Networking::Voip::MuteChangeEventArgs> const*>(&muteChangeHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_MuteRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MuteRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_UnmuteRequested(void* muteChangeHandler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().UnmuteRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipCallCoordinator, llm::OS::Phone::Networking::Voip::MuteChangeEventArgs> const*>(&muteChangeHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_UnmuteRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnmuteRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall RequestNewIncomingCall(void* context, void* contactName, void* contactNumber, void* contactImage, void* serviceName, void* brandingImage, void* callDetails, void* ringtone, uint32_t media, int64_t ringTimeout, void** call) noexcept final try
        {
            clear_abi(call);
            typename D::abi_guard guard(this->shim());
            this->shim().RequestNewIncomingCall(*reinterpret_cast<hstring const*>(&context), *reinterpret_cast<hstring const*>(&contactName), *reinterpret_cast<hstring const*>(&contactNumber), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&contactImage), *reinterpret_cast<hstring const*>(&serviceName), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&brandingImage), *reinterpret_cast<hstring const*>(&callDetails), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&ringtone), *reinterpret_cast<llm::OS::Phone::Networking::Voip::VoipCallMedia const*>(&media), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&ringTimeout), *reinterpret_cast<llm::OS::Phone::Networking::Voip::VoipPhoneCall*>(call));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestNewOutgoingCall(void* context, void* contactName, void* serviceName, uint32_t media, void** call) noexcept final try
        {
            clear_abi(call);
            typename D::abi_guard guard(this->shim());
            this->shim().RequestNewOutgoingCall(*reinterpret_cast<hstring const*>(&context), *reinterpret_cast<hstring const*>(&contactName), *reinterpret_cast<hstring const*>(&serviceName), *reinterpret_cast<llm::OS::Phone::Networking::Voip::VoipCallMedia const*>(&media), *reinterpret_cast<llm::OS::Phone::Networking::Voip::VoipPhoneCall*>(call));
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
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::Networking::Voip::IVoipCallCoordinator2> : produce_base<D, llm::OS::Phone::Networking::Voip::IVoipCallCoordinator2>
    {
        int32_t __stdcall SetupNewAcceptedCall(void* context, void* contactName, void* contactNumber, void* serviceName, uint32_t media, void** call) noexcept final try
        {
            clear_abi(call);
            typename D::abi_guard guard(this->shim());
            this->shim().SetupNewAcceptedCall(*reinterpret_cast<hstring const*>(&context), *reinterpret_cast<hstring const*>(&contactName), *reinterpret_cast<hstring const*>(&contactNumber), *reinterpret_cast<hstring const*>(&serviceName), *reinterpret_cast<llm::OS::Phone::Networking::Voip::VoipCallMedia const*>(&media), *reinterpret_cast<llm::OS::Phone::Networking::Voip::VoipPhoneCall*>(call));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::Networking::Voip::IVoipCallCoordinator3> : produce_base<D, llm::OS::Phone::Networking::Voip::IVoipCallCoordinator3>
    {
        int32_t __stdcall RequestNewIncomingCallWithContactRemoteId(void* context, void* contactName, void* contactNumber, void* contactImage, void* serviceName, void* brandingImage, void* callDetails, void* ringtone, uint32_t media, int64_t ringTimeout, void* contactRemoteId, void** call) noexcept final try
        {
            clear_abi(call);
            typename D::abi_guard guard(this->shim());
            *call = detach_from<llm::OS::Phone::Networking::Voip::VoipPhoneCall>(this->shim().RequestNewIncomingCall(*reinterpret_cast<hstring const*>(&context), *reinterpret_cast<hstring const*>(&contactName), *reinterpret_cast<hstring const*>(&contactNumber), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&contactImage), *reinterpret_cast<hstring const*>(&serviceName), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&brandingImage), *reinterpret_cast<hstring const*>(&callDetails), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&ringtone), *reinterpret_cast<llm::OS::Phone::Networking::Voip::VoipCallMedia const*>(&media), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&ringTimeout), *reinterpret_cast<hstring const*>(&contactRemoteId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestNewAppInitiatedCall(void* context, void* contactName, void* contactNumber, void* serviceName, uint32_t media, void** call) noexcept final try
        {
            clear_abi(call);
            typename D::abi_guard guard(this->shim());
            this->shim().RequestNewAppInitiatedCall(*reinterpret_cast<hstring const*>(&context), *reinterpret_cast<hstring const*>(&contactName), *reinterpret_cast<hstring const*>(&contactNumber), *reinterpret_cast<hstring const*>(&serviceName), *reinterpret_cast<llm::OS::Phone::Networking::Voip::VoipCallMedia const*>(&media), *reinterpret_cast<llm::OS::Phone::Networking::Voip::VoipPhoneCall*>(call));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::Networking::Voip::IVoipCallCoordinatorStatics> : produce_base<D, llm::OS::Phone::Networking::Voip::IVoipCallCoordinatorStatics>
    {
        int32_t __stdcall GetDefault(void** coordinator) noexcept final try
        {
            clear_abi(coordinator);
            typename D::abi_guard guard(this->shim());
            *coordinator = detach_from<llm::OS::Phone::Networking::Voip::VoipCallCoordinator>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::Networking::Voip::IVoipCallCoordinatorWithAppDeterminedUpgrade> : produce_base<D, llm::OS::Phone::Networking::Voip::IVoipCallCoordinatorWithAppDeterminedUpgrade>
    {
        int32_t __stdcall ConfirmNonSeamlessUpgrade(llm::guid callUpgradeGuid) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConfirmNonSeamlessUpgrade(*reinterpret_cast<llm::guid const*>(&callUpgradeGuid));
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
    struct produce<D, llm::OS::Phone::Networking::Voip::IVoipCallCoordinatorWithUpgrade> : produce_base<D, llm::OS::Phone::Networking::Voip::IVoipCallCoordinatorWithUpgrade>
    {
        int32_t __stdcall RequestOutgoingUpgradeToVideoCall(llm::guid callUpgradeGuid, void* context, void* contactName, void* serviceName, void** call) noexcept final try
        {
            clear_abi(call);
            typename D::abi_guard guard(this->shim());
            this->shim().RequestOutgoingUpgradeToVideoCall(*reinterpret_cast<llm::guid const*>(&callUpgradeGuid), *reinterpret_cast<hstring const*>(&context), *reinterpret_cast<hstring const*>(&contactName), *reinterpret_cast<hstring const*>(&serviceName), *reinterpret_cast<llm::OS::Phone::Networking::Voip::VoipPhoneCall*>(call));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestIncomingUpgradeToVideoCall(void* context, void* contactName, void* contactNumber, void* contactImage, void* serviceName, void* brandingImage, void* callDetails, void* ringtone, int64_t ringTimeout, void** call) noexcept final try
        {
            clear_abi(call);
            typename D::abi_guard guard(this->shim());
            this->shim().RequestIncomingUpgradeToVideoCall(*reinterpret_cast<hstring const*>(&context), *reinterpret_cast<hstring const*>(&contactName), *reinterpret_cast<hstring const*>(&contactNumber), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&contactImage), *reinterpret_cast<hstring const*>(&serviceName), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&brandingImage), *reinterpret_cast<hstring const*>(&callDetails), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&ringtone), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&ringTimeout), *reinterpret_cast<llm::OS::Phone::Networking::Voip::VoipPhoneCall*>(call));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Phone::Networking::Voip::IVoipOperation> : produce_base<D, llm::OS::Phone::Networking::Voip::IVoipOperation>
    {
        int32_t __stdcall get_Id(uint32_t* operationId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *operationId = detach_from<uint32_t>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Type(int32_t* operationType) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *operationType = detach_from<llm::OS::Phone::Networking::Voip::VoipOperationType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::Networking::Voip::IVoipOperationsManager> : produce_base<D, llm::OS::Phone::Networking::Voip::IVoipOperationsManager>
    {
        int32_t __stdcall GetNextOperation(void** voipOperation) noexcept final try
        {
            clear_abi(voipOperation);
            typename D::abi_guard guard(this->shim());
            *voipOperation = detach_from<llm::OS::Phone::Networking::Voip::IVoipOperation>(this->shim().GetNextOperation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::Networking::Voip::IVoipPhoneCall> : produce_base<D, llm::OS::Phone::Networking::Voip::IVoipPhoneCall>
    {
        int32_t __stdcall add_EndRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().EndRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipPhoneCall, llm::OS::Phone::Networking::Voip::CallStateChangeEventArgs> const*>(&handler)));
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
            *token = detach_from<llm::event_token>(this->shim().HoldRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipPhoneCall, llm::OS::Phone::Networking::Voip::CallStateChangeEventArgs> const*>(&handler)));
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
            *token = detach_from<llm::event_token>(this->shim().ResumeRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipPhoneCall, llm::OS::Phone::Networking::Voip::CallStateChangeEventArgs> const*>(&handler)));
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
            *token = detach_from<llm::event_token>(this->shim().AnswerRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipPhoneCall, llm::OS::Phone::Networking::Voip::CallAnswerEventArgs> const*>(&acceptHandler)));
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
            *token = detach_from<llm::event_token>(this->shim().RejectRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Phone::Networking::Voip::VoipPhoneCall, llm::OS::Phone::Networking::Voip::CallRejectEventArgs> const*>(&rejectHandler)));
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
            *value = detach_from<llm::OS::Phone::Networking::Voip::VoipCallMedia>(this->shim().CallMedia());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CallMedia(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CallMedia(*reinterpret_cast<llm::OS::Phone::Networking::Voip::VoipCallMedia const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::Networking::Voip::IVoipPhoneCall2> : produce_base<D, llm::OS::Phone::Networking::Voip::IVoipPhoneCall2>
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
    struct produce<D, llm::OS::Phone::Networking::Voip::IVoipPhoneCall3> : produce_base<D, llm::OS::Phone::Networking::Voip::IVoipPhoneCall3>
    {
        int32_t __stdcall NotifyCallAccepted(uint32_t media) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyCallAccepted(*reinterpret_cast<llm::OS::Phone::Networking::Voip::VoipCallMedia const*>(&media));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Phone::Networking::Voip::IVoipPhoneCallReady> : produce_base<D, llm::OS::Phone::Networking::Voip::IVoipPhoneCallReady>
    {
        int32_t __stdcall NotifyCallReady() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyCallReady();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Phone::Networking::Voip
{
    constexpr auto operator|(VoipCallMedia const left, VoipCallMedia const right) noexcept
    {
        return static_cast<VoipCallMedia>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(VoipCallMedia& left, VoipCallMedia const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(VoipCallMedia const left, VoipCallMedia const right) noexcept
    {
        return static_cast<VoipCallMedia>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(VoipCallMedia& left, VoipCallMedia const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(VoipCallMedia const value) noexcept
    {
        return static_cast<VoipCallMedia>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(VoipCallMedia const left, VoipCallMedia const right) noexcept
    {
        return static_cast<VoipCallMedia>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(VoipCallMedia& left, VoipCallMedia const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto VoipCallCoordinator::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::Phone::Networking::Voip::VoipCallCoordinator(*)(IVoipCallCoordinatorStatics const&), VoipCallCoordinator, IVoipCallCoordinatorStatics>([](IVoipCallCoordinatorStatics const& f) { return f.GetDefault(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Phone::Networking::Voip::ICallAnswerEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::ICallRejectEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::ICallStateChangeEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::IMuteChangeEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::IQuerySeamlessUpgradeSupportOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::IVoipCallCoordinator> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::IVoipCallCoordinator2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::IVoipCallCoordinator3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::IVoipCallCoordinatorStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::IVoipCallCoordinatorWithAppDeterminedUpgrade> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::IVoipCallCoordinatorWithUpgrade> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::IVoipOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::IVoipOperationsManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::IVoipPhoneCall> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::IVoipPhoneCall2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::IVoipPhoneCall3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::IVoipPhoneCallReady> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::CallAnswerEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::CallRejectEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::CallStateChangeEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::MuteChangeEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::QuerySeamlessUpgradeSupportOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::VoipCallCoordinator> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Phone::Networking::Voip::VoipPhoneCall> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
