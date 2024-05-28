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
#ifndef LLM_OS_Security_Authentication_OnlineId_H
#define LLM_OS_Security_Authentication_OnlineId_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.Security.Authentication.OnlineId.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::OnlineId::UserAuthenticationOperation) consume_Windows_Security_Authentication_OnlineId_IOnlineIdAuthenticator<D>::AuthenticateUserAsync(llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest const& request) const
    {
        void* authenticationOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator)->AuthenticateUserAsync(*(void**)(&request), &authenticationOperation));
        return llm::OS::Security::Authentication::OnlineId::UserAuthenticationOperation{ authenticationOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::OnlineId::UserAuthenticationOperation) consume_Windows_Security_Authentication_OnlineId_IOnlineIdAuthenticator<D>::AuthenticateUserAsync(param::iterable<llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest> const& requests, llm::OS::Security::Authentication::OnlineId::CredentialPromptType const& credentialPromptType) const
    {
        void* authenticationOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator)->AuthenticateUserAsyncAdvanced(*(void**)(&requests), static_cast<int32_t>(credentialPromptType), &authenticationOperation));
        return llm::OS::Security::Authentication::OnlineId::UserAuthenticationOperation{ authenticationOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::OnlineId::SignOutUserOperation) consume_Windows_Security_Authentication_OnlineId_IOnlineIdAuthenticator<D>::SignOutUserAsync() const
    {
        void* signOutUserOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator)->SignOutUserAsync(&signOutUserOperation));
        return llm::OS::Security::Authentication::OnlineId::SignOutUserOperation{ signOutUserOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Authentication_OnlineId_IOnlineIdAuthenticator<D>::ApplicationId(llm::guid const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator)->put_ApplicationId(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Security_Authentication_OnlineId_IOnlineIdAuthenticator<D>::ApplicationId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator)->get_ApplicationId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Security_Authentication_OnlineId_IOnlineIdAuthenticator<D>::CanSignOut() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator)->get_CanSignOut(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_OnlineId_IOnlineIdAuthenticator<D>::AuthenticatedSafeCustomerId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator)->get_AuthenticatedSafeCustomerId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_OnlineId_IOnlineIdServiceTicket<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdServiceTicket)->get_Value(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest) consume_Windows_Security_Authentication_OnlineId_IOnlineIdServiceTicket<D>::Request() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdServiceTicket)->get_Request(&value));
        return llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Security_Authentication_OnlineId_IOnlineIdServiceTicket<D>::ErrorCode() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdServiceTicket)->get_ErrorCode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_OnlineId_IOnlineIdServiceTicketRequest<D>::Service() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest)->get_Service(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_OnlineId_IOnlineIdServiceTicketRequest<D>::Policy() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest)->get_Policy(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest) consume_Windows_Security_Authentication_OnlineId_IOnlineIdServiceTicketRequestFactory<D>::CreateOnlineIdServiceTicketRequest(param::hstring const& service, param::hstring const& policy) const
    {
        void* onlineIdServiceTicketRequest{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequestFactory)->CreateOnlineIdServiceTicketRequest(*(void**)(&service), *(void**)(&policy), &onlineIdServiceTicketRequest));
        return llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest{ onlineIdServiceTicketRequest, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest) consume_Windows_Security_Authentication_OnlineId_IOnlineIdServiceTicketRequestFactory<D>::CreateOnlineIdServiceTicketRequestAdvanced(param::hstring const& service) const
    {
        void* onlineIdServiceTicketRequest{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequestFactory)->CreateOnlineIdServiceTicketRequestAdvanced(*(void**)(&service), &onlineIdServiceTicketRequest));
        return llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest{ onlineIdServiceTicketRequest, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::OnlineId::OnlineIdSystemTicketResult>) consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemAuthenticatorForUser<D>::GetTicketAsync(llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest const& request) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser)->GetTicketAsync(*(void**)(&request), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::OnlineId::OnlineIdSystemTicketResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemAuthenticatorForUser<D>::ApplicationId(llm::guid const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser)->put_ApplicationId(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemAuthenticatorForUser<D>::ApplicationId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser)->get_ApplicationId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemAuthenticatorForUser<D>::User() const
    {
        void* user{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser)->get_User(&user));
        return llm::OS::System::User{ user, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::OnlineId::OnlineIdSystemAuthenticatorForUser) consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemAuthenticatorStatics<D>::Default() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorStatics)->get_Default(&value));
        return llm::OS::Security::Authentication::OnlineId::OnlineIdSystemAuthenticatorForUser{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::OnlineId::OnlineIdSystemAuthenticatorForUser) consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemAuthenticatorStatics<D>::GetForUser(llm::OS::System::User const& user) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorStatics)->GetForUser(*(void**)(&user), &value));
        return llm::OS::Security::Authentication::OnlineId::OnlineIdSystemAuthenticatorForUser{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicket) consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemIdentity<D>::Ticket() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemIdentity)->get_Ticket(&value));
        return llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicket{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemIdentity<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemIdentity)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::OnlineId::OnlineIdSystemIdentity) consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemTicketResult<D>::Identity() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult)->get_Identity(&value));
        return llm::OS::Security::Authentication::OnlineId::OnlineIdSystemIdentity{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::OnlineId::OnlineIdSystemTicketStatus) consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemTicketResult<D>::Status() const
    {
        llm::OS::Security::Authentication::OnlineId::OnlineIdSystemTicketStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemTicketResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicket>) consume_Windows_Security_Authentication_OnlineId_IUserIdentity<D>::Tickets() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IUserIdentity)->get_Tickets(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicket>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_OnlineId_IUserIdentity<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IUserIdentity)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_OnlineId_IUserIdentity<D>::SafeCustomerId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IUserIdentity)->get_SafeCustomerId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_OnlineId_IUserIdentity<D>::SignInName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IUserIdentity)->get_SignInName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_OnlineId_IUserIdentity<D>::FirstName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IUserIdentity)->get_FirstName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_OnlineId_IUserIdentity<D>::LastName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IUserIdentity)->get_LastName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Security_Authentication_OnlineId_IUserIdentity<D>::IsBetaAccount() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IUserIdentity)->get_IsBetaAccount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Security_Authentication_OnlineId_IUserIdentity<D>::IsConfirmedPC() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::OnlineId::IUserIdentity)->get_IsConfirmedPC(&value));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator> : produce_base<D, llm::OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator>
    {
        int32_t __stdcall AuthenticateUserAsync(void* request, void** authenticationOperation) noexcept final try
        {
            clear_abi(authenticationOperation);
            typename D::abi_guard guard(this->shim());
            *authenticationOperation = detach_from<llm::OS::Security::Authentication::OnlineId::UserAuthenticationOperation>(this->shim().AuthenticateUserAsync(*reinterpret_cast<llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest const*>(&request)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AuthenticateUserAsyncAdvanced(void* requests, int32_t credentialPromptType, void** authenticationOperation) noexcept final try
        {
            clear_abi(authenticationOperation);
            typename D::abi_guard guard(this->shim());
            *authenticationOperation = detach_from<llm::OS::Security::Authentication::OnlineId::UserAuthenticationOperation>(this->shim().AuthenticateUserAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest> const*>(&requests), *reinterpret_cast<llm::OS::Security::Authentication::OnlineId::CredentialPromptType const*>(&credentialPromptType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SignOutUserAsync(void** signOutUserOperation) noexcept final try
        {
            clear_abi(signOutUserOperation);
            typename D::abi_guard guard(this->shim());
            *signOutUserOperation = detach_from<llm::OS::Security::Authentication::OnlineId::SignOutUserOperation>(this->shim().SignOutUserAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ApplicationId(llm::guid value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ApplicationId(*reinterpret_cast<llm::guid const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ApplicationId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().ApplicationId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanSignOut(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanSignOut());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AuthenticatedSafeCustomerId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AuthenticatedSafeCustomerId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::OnlineId::IOnlineIdServiceTicket> : produce_base<D, llm::OS::Security::Authentication::OnlineId::IOnlineIdServiceTicket>
    {
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Request(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest>(this->shim().Request());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ErrorCode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ErrorCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest> : produce_base<D, llm::OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest>
    {
        int32_t __stdcall get_Service(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Service());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Policy(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Policy());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequestFactory> : produce_base<D, llm::OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequestFactory>
    {
        int32_t __stdcall CreateOnlineIdServiceTicketRequest(void* service, void* policy, void** onlineIdServiceTicketRequest) noexcept final try
        {
            clear_abi(onlineIdServiceTicketRequest);
            typename D::abi_guard guard(this->shim());
            *onlineIdServiceTicketRequest = detach_from<llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest>(this->shim().CreateOnlineIdServiceTicketRequest(*reinterpret_cast<hstring const*>(&service), *reinterpret_cast<hstring const*>(&policy)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateOnlineIdServiceTicketRequestAdvanced(void* service, void** onlineIdServiceTicketRequest) noexcept final try
        {
            clear_abi(onlineIdServiceTicketRequest);
            typename D::abi_guard guard(this->shim());
            *onlineIdServiceTicketRequest = detach_from<llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest>(this->shim().CreateOnlineIdServiceTicketRequestAdvanced(*reinterpret_cast<hstring const*>(&service)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser> : produce_base<D, llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser>
    {
        int32_t __stdcall GetTicketAsync(void* request, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::OnlineId::OnlineIdSystemTicketResult>>(this->shim().GetTicketAsync(*reinterpret_cast<llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest const*>(&request)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ApplicationId(llm::guid value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ApplicationId(*reinterpret_cast<llm::guid const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ApplicationId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().ApplicationId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_User(void** user) noexcept final try
        {
            clear_abi(user);
            typename D::abi_guard guard(this->shim());
            *user = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorStatics> : produce_base<D, llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorStatics>
    {
        int32_t __stdcall get_Default(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::OnlineId::OnlineIdSystemAuthenticatorForUser>(this->shim().Default());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetForUser(void* user, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::OnlineId::OnlineIdSystemAuthenticatorForUser>(this->shim().GetForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemIdentity> : produce_base<D, llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemIdentity>
    {
        int32_t __stdcall get_Ticket(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicket>(this->shim().Ticket());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult> : produce_base<D, llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult>
    {
        int32_t __stdcall get_Identity(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::OnlineId::OnlineIdSystemIdentity>(this->shim().Identity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::OnlineId::OnlineIdSystemTicketStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::OnlineId::IUserIdentity> : produce_base<D, llm::OS::Security::Authentication::OnlineId::IUserIdentity>
    {
        int32_t __stdcall get_Tickets(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicket>>(this->shim().Tickets());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SafeCustomerId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SafeCustomerId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SignInName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SignInName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FirstName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FirstName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LastName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().LastName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsBetaAccount(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsBetaAccount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsConfirmedPC(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsConfirmedPC());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Security::Authentication::OnlineId
{
    inline OnlineIdAuthenticator::OnlineIdAuthenticator() :
        OnlineIdAuthenticator(impl::call_factory_cast<OnlineIdAuthenticator(*)(llm::OS::Foundation::IActivationFactory const&), OnlineIdAuthenticator>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<OnlineIdAuthenticator>(); }))
    {
    }
    inline OnlineIdServiceTicketRequest::OnlineIdServiceTicketRequest(param::hstring const& service, param::hstring const& policy) :
        OnlineIdServiceTicketRequest(impl::call_factory<OnlineIdServiceTicketRequest, IOnlineIdServiceTicketRequestFactory>([&](IOnlineIdServiceTicketRequestFactory const& f) { return f.CreateOnlineIdServiceTicketRequest(service, policy); }))
    {
    }
    inline OnlineIdServiceTicketRequest::OnlineIdServiceTicketRequest(param::hstring const& service) :
        OnlineIdServiceTicketRequest(impl::call_factory<OnlineIdServiceTicketRequest, IOnlineIdServiceTicketRequestFactory>([&](IOnlineIdServiceTicketRequestFactory const& f) { return f.CreateOnlineIdServiceTicketRequestAdvanced(service); }))
    {
    }
    inline auto OnlineIdSystemAuthenticator::Default()
    {
        return impl::call_factory_cast<llm::OS::Security::Authentication::OnlineId::OnlineIdSystemAuthenticatorForUser(*)(IOnlineIdSystemAuthenticatorStatics const&), OnlineIdSystemAuthenticator, IOnlineIdSystemAuthenticatorStatics>([](IOnlineIdSystemAuthenticatorStatics const& f) { return f.Default(); });
    }
    inline auto OnlineIdSystemAuthenticator::GetForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<OnlineIdSystemAuthenticator, IOnlineIdSystemAuthenticatorStatics>([&](IOnlineIdSystemAuthenticatorStatics const& f) { return f.GetForUser(user); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::IOnlineIdServiceTicket> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequestFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemIdentity> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::IUserIdentity> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::OnlineIdAuthenticator> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicket> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::OnlineIdSystemAuthenticator> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::OnlineIdSystemAuthenticatorForUser> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::OnlineIdSystemIdentity> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::OnlineIdSystemTicketResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::SignOutUserOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::UserAuthenticationOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::OnlineId::UserIdentity> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
