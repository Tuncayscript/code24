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
#ifndef LLM_OS_Security_Authentication_Identity_Core_H
#define LLM_OS_Security_Authentication_Identity_Core_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Security.Authentication.Identity.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Security.Authentication.Identity.Core.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo>) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorAuthenticationManager<D>::GetOneTimePassCodeAsync(param::hstring const& userAccountId, uint32_t codeLength) const
    {
        void* asyncOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager)->GetOneTimePassCodeAsync(*(void**)(&userAccountId), codeLength, &asyncOperation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo>{ asyncOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorAuthenticationManager<D>::AddDeviceAsync(param::hstring const& userAccountId, param::hstring const& authenticationToken, param::hstring const& wnsChannelId) const
    {
        void* asyncOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager)->AddDeviceAsync(*(void**)(&userAccountId), *(void**)(&authenticationToken), *(void**)(&wnsChannelId), &asyncOperation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>{ asyncOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorAuthenticationManager<D>::RemoveDeviceAsync(param::hstring const& userAccountId) const
    {
        void* asyncOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager)->RemoveDeviceAsync(*(void**)(&userAccountId), &asyncOperation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>{ asyncOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorAuthenticationManager<D>::UpdateWnsChannelAsync(param::hstring const& userAccountId, param::hstring const& channelUri) const
    {
        void* asyncOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager)->UpdateWnsChannelAsync(*(void**)(&userAccountId), *(void**)(&channelUri), &asyncOperation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>{ asyncOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult>) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorAuthenticationManager<D>::GetSessionsAsync(param::async_iterable<hstring> const& userAccountIdList) const
    {
        void* asyncOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager)->GetSessionsAsync(*(void**)(&userAccountIdList), &asyncOperation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult>{ asyncOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorAuthenticationManager<D>::GetSessionsAndUnregisteredAccountsAsync(param::async_iterable<hstring> const& userAccountIdList) const
    {
        void* asyncOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager)->GetSessionsAndUnregisteredAccountsAsync(*(void**)(&userAccountIdList), &asyncOperation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>{ asyncOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorAuthenticationManager<D>::ApproveSessionAsync(llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus const& sessionAuthentictionStatus, llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo const& authenticationSessionInfo) const
    {
        void* asyncOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager)->ApproveSessionUsingAuthSessionInfoAsync(static_cast<int32_t>(sessionAuthentictionStatus), *(void**)(&authenticationSessionInfo), &asyncOperation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>{ asyncOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorAuthenticationManager<D>::ApproveSessionAsync(llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus const& sessionAuthentictionStatus, param::hstring const& userAccountId, param::hstring const& sessionId, llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType const& sessionAuthenticationType) const
    {
        void* asyncOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager)->ApproveSessionAsync(static_cast<int32_t>(sessionAuthentictionStatus), *(void**)(&userAccountId), *(void**)(&sessionId), static_cast<int32_t>(sessionAuthenticationType), &asyncOperation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>{ asyncOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorAuthenticationManager<D>::DenySessionAsync(llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo const& authenticationSessionInfo) const
    {
        void* asyncOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager)->DenySessionUsingAuthSessionInfoAsync(*(void**)(&authenticationSessionInfo), &asyncOperation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>{ asyncOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorAuthenticationManager<D>::DenySessionAsync(param::hstring const& userAccountId, param::hstring const& sessionId, llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType const& sessionAuthenticationType) const
    {
        void* asyncOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager)->DenySessionAsync(*(void**)(&userAccountId), *(void**)(&sessionId), static_cast<int32_t>(sessionAuthenticationType), &asyncOperation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>{ asyncOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorAuthenticatorStatics<D>::Current() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticatorStatics)->get_Current(&value));
        return llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo>) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorGetSessionsResult<D>::Sessions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult)->get_Sessions(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorGetSessionsResult<D>::ServiceResponse() const
    {
        llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult)->get_ServiceResponse(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorOneTimeCodedInfo<D>::Code() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo)->get_Code(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorOneTimeCodedInfo<D>::TimeInterval() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo)->get_TimeInterval(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorOneTimeCodedInfo<D>::TimeToLive() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo)->get_TimeToLive(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorOneTimeCodedInfo<D>::ServiceResponse() const
    {
        llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo)->get_ServiceResponse(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorSessionInfo<D>::UserAccountId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo)->get_UserAccountId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorSessionInfo<D>::SessionId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo)->get_SessionId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorSessionInfo<D>::DisplaySessionId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo)->get_DisplaySessionId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionApprovalStatus) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorSessionInfo<D>::ApprovalStatus() const
    {
        llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionApprovalStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo)->get_ApprovalStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorSessionInfo<D>::AuthenticationType() const
    {
        llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo)->get_AuthenticationType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorSessionInfo<D>::RequestTime() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo)->get_RequestTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorSessionInfo<D>::ExpirationTime() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo)->get_ExpirationTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo>) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo<D>::Sessions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo)->get_Sessions(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo<D>::UnregisteredAccounts() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo)->get_UnregisteredAccounts(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse) consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo<D>::ServiceResponse() const
    {
        llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo)->get_ServiceResponse(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager> : produce_base<D, llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager>
    {
        int32_t __stdcall GetOneTimePassCodeAsync(void* userAccountId, uint32_t codeLength, void** asyncOperation) noexcept final try
        {
            clear_abi(asyncOperation);
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo>>(this->shim().GetOneTimePassCodeAsync(*reinterpret_cast<hstring const*>(&userAccountId), codeLength));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddDeviceAsync(void* userAccountId, void* authenticationToken, void* wnsChannelId, void** asyncOperation) noexcept final try
        {
            clear_abi(asyncOperation);
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>>(this->shim().AddDeviceAsync(*reinterpret_cast<hstring const*>(&userAccountId), *reinterpret_cast<hstring const*>(&authenticationToken), *reinterpret_cast<hstring const*>(&wnsChannelId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveDeviceAsync(void* userAccountId, void** asyncOperation) noexcept final try
        {
            clear_abi(asyncOperation);
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>>(this->shim().RemoveDeviceAsync(*reinterpret_cast<hstring const*>(&userAccountId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateWnsChannelAsync(void* userAccountId, void* channelUri, void** asyncOperation) noexcept final try
        {
            clear_abi(asyncOperation);
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>>(this->shim().UpdateWnsChannelAsync(*reinterpret_cast<hstring const*>(&userAccountId), *reinterpret_cast<hstring const*>(&channelUri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSessionsAsync(void* userAccountIdList, void** asyncOperation) noexcept final try
        {
            clear_abi(asyncOperation);
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult>>(this->shim().GetSessionsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&userAccountIdList)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSessionsAndUnregisteredAccountsAsync(void* userAccountIdList, void** asyncOperation) noexcept final try
        {
            clear_abi(asyncOperation);
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>>(this->shim().GetSessionsAndUnregisteredAccountsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&userAccountIdList)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ApproveSessionUsingAuthSessionInfoAsync(int32_t sessionAuthentictionStatus, void* authenticationSessionInfo, void** asyncOperation) noexcept final try
        {
            clear_abi(asyncOperation);
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>>(this->shim().ApproveSessionAsync(*reinterpret_cast<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus const*>(&sessionAuthentictionStatus), *reinterpret_cast<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo const*>(&authenticationSessionInfo)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ApproveSessionAsync(int32_t sessionAuthentictionStatus, void* userAccountId, void* sessionId, int32_t sessionAuthenticationType, void** asyncOperation) noexcept final try
        {
            clear_abi(asyncOperation);
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>>(this->shim().ApproveSessionAsync(*reinterpret_cast<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus const*>(&sessionAuthentictionStatus), *reinterpret_cast<hstring const*>(&userAccountId), *reinterpret_cast<hstring const*>(&sessionId), *reinterpret_cast<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType const*>(&sessionAuthenticationType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DenySessionUsingAuthSessionInfoAsync(void* authenticationSessionInfo, void** asyncOperation) noexcept final try
        {
            clear_abi(asyncOperation);
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>>(this->shim().DenySessionAsync(*reinterpret_cast<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo const*>(&authenticationSessionInfo)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DenySessionAsync(void* userAccountId, void* sessionId, int32_t sessionAuthenticationType, void** asyncOperation) noexcept final try
        {
            clear_abi(asyncOperation);
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>>(this->shim().DenySessionAsync(*reinterpret_cast<hstring const*>(&userAccountId), *reinterpret_cast<hstring const*>(&sessionId), *reinterpret_cast<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType const*>(&sessionAuthenticationType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticatorStatics> : produce_base<D, llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticatorStatics>
    {
        int32_t __stdcall get_Current(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager>(this->shim().Current());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult> : produce_base<D, llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult>
    {
        int32_t __stdcall get_Sessions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo>>(this->shim().Sessions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServiceResponse(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>(this->shim().ServiceResponse());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo> : produce_base<D, llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo>
    {
        int32_t __stdcall get_Code(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Code());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TimeInterval(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().TimeInterval());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TimeToLive(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().TimeToLive());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServiceResponse(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>(this->shim().ServiceResponse());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo> : produce_base<D, llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo>
    {
        int32_t __stdcall get_UserAccountId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().UserAccountId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SessionId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SessionId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplaySessionId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplaySessionId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ApprovalStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionApprovalStatus>(this->shim().ApprovalStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AuthenticationType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType>(this->shim().AuthenticationType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RequestTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().RequestTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExpirationTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().ExpirationTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo> : produce_base<D, llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>
    {
        int32_t __stdcall get_Sessions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo>>(this->shim().Sessions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UnregisteredAccounts(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().UnregisteredAccounts());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServiceResponse(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>(this->shim().ServiceResponse());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Security::Authentication::Identity::Core
{
    inline auto MicrosoftAccountMultiFactorAuthenticationManager::Current()
    {
        return impl::call_factory_cast<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager(*)(IMicrosoftAccountMultiFactorAuthenticatorStatics const&), MicrosoftAccountMultiFactorAuthenticationManager, IMicrosoftAccountMultiFactorAuthenticatorStatics>([](IMicrosoftAccountMultiFactorAuthenticatorStatics const& f) { return f.Current(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticatorStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
