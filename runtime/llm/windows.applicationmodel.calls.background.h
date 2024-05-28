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
#ifndef LLM_OS_ApplicationModel_Calls_Background_H
#define LLM_OS_ApplicationModel_Calls_Background_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.Calls.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.ApplicationModel.Calls.Background.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_Background_IPhoneCallBlockedTriggerDetails<D>::PhoneNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneCallBlockedTriggerDetails)->get_PhoneNumber(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_Calls_Background_IPhoneCallBlockedTriggerDetails<D>::LineId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneCallBlockedTriggerDetails)->get_LineId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::Background::PhoneCallBlockedReason) consume_Windows_ApplicationModel_Calls_Background_IPhoneCallBlockedTriggerDetails<D>::CallBlockedReason() const
    {
        llm::OS::ApplicationModel::Calls::Background::PhoneCallBlockedReason value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneCallBlockedTriggerDetails)->get_CallBlockedReason(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_Calls_Background_IPhoneCallOriginDataRequestTriggerDetails<D>::RequestId() const
    {
        llm::guid result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneCallOriginDataRequestTriggerDetails)->get_RequestId(put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_Background_IPhoneCallOriginDataRequestTriggerDetails<D>::PhoneNumber() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneCallOriginDataRequestTriggerDetails)->get_PhoneNumber(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_Calls_Background_IPhoneIncomingCallDismissedTriggerDetails<D>::LineId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallDismissedTriggerDetails)->get_LineId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_Background_IPhoneIncomingCallDismissedTriggerDetails<D>::PhoneNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallDismissedTriggerDetails)->get_PhoneNumber(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_Background_IPhoneIncomingCallDismissedTriggerDetails<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallDismissedTriggerDetails)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_ApplicationModel_Calls_Background_IPhoneIncomingCallDismissedTriggerDetails<D>::DismissalTime() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallDismissedTriggerDetails)->get_DismissalTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_Background_IPhoneIncomingCallDismissedTriggerDetails<D>::TextReplyMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallDismissedTriggerDetails)->get_TextReplyMessage(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::Background::PhoneIncomingCallDismissedReason) consume_Windows_ApplicationModel_Calls_Background_IPhoneIncomingCallDismissedTriggerDetails<D>::Reason() const
    {
        llm::OS::ApplicationModel::Calls::Background::PhoneIncomingCallDismissedReason value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallDismissedTriggerDetails)->get_Reason(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_Calls_Background_IPhoneIncomingCallNotificationTriggerDetails<D>::LineId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallNotificationTriggerDetails)->get_LineId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_Background_IPhoneIncomingCallNotificationTriggerDetails<D>::CallId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallNotificationTriggerDetails)->get_CallId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_Calls_Background_IPhoneLineChangedTriggerDetails<D>::LineId() const
    {
        llm::guid result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneLineChangedTriggerDetails)->get_LineId(put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::Background::PhoneLineChangeKind) consume_Windows_ApplicationModel_Calls_Background_IPhoneLineChangedTriggerDetails<D>::ChangeType() const
    {
        llm::OS::ApplicationModel::Calls::Background::PhoneLineChangeKind result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneLineChangedTriggerDetails)->get_ChangeType(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_Background_IPhoneLineChangedTriggerDetails<D>::HasLinePropertyChanged(llm::OS::ApplicationModel::Calls::Background::PhoneLineProperties const& lineProperty) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneLineChangedTriggerDetails)->HasLinePropertyChanged(static_cast<uint32_t>(lineProperty), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_Calls_Background_IPhoneNewVoicemailMessageTriggerDetails<D>::LineId() const
    {
        llm::guid result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneNewVoicemailMessageTriggerDetails)->get_LineId(put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_ApplicationModel_Calls_Background_IPhoneNewVoicemailMessageTriggerDetails<D>::VoicemailCount() const
    {
        int32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneNewVoicemailMessageTriggerDetails)->get_VoicemailCount(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_Background_IPhoneNewVoicemailMessageTriggerDetails<D>::OperatorMessage() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Background::IPhoneNewVoicemailMessageTriggerDetails)->get_OperatorMessage(&result));
        return hstring{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::Background::IPhoneCallBlockedTriggerDetails> : produce_base<D, llm::OS::ApplicationModel::Calls::Background::IPhoneCallBlockedTriggerDetails>
    {
        int32_t __stdcall get_PhoneNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PhoneNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LineId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().LineId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CallBlockedReason(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::Background::PhoneCallBlockedReason>(this->shim().CallBlockedReason());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::Background::IPhoneCallOriginDataRequestTriggerDetails> : produce_base<D, llm::OS::ApplicationModel::Calls::Background::IPhoneCallOriginDataRequestTriggerDetails>
    {
        int32_t __stdcall get_RequestId(llm::guid* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::guid>(this->shim().RequestId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhoneNumber(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().PhoneNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallDismissedTriggerDetails> : produce_base<D, llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallDismissedTriggerDetails>
    {
        int32_t __stdcall get_LineId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().LineId());
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
        int32_t __stdcall get_DismissalTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().DismissalTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TextReplyMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TextReplyMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Reason(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::Background::PhoneIncomingCallDismissedReason>(this->shim().Reason());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallNotificationTriggerDetails> : produce_base<D, llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallNotificationTriggerDetails>
    {
        int32_t __stdcall get_LineId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().LineId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CallId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CallId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::Background::IPhoneLineChangedTriggerDetails> : produce_base<D, llm::OS::ApplicationModel::Calls::Background::IPhoneLineChangedTriggerDetails>
    {
        int32_t __stdcall get_LineId(llm::guid* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::guid>(this->shim().LineId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ChangeType(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::Background::PhoneLineChangeKind>(this->shim().ChangeType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall HasLinePropertyChanged(uint32_t lineProperty, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().HasLinePropertyChanged(*reinterpret_cast<llm::OS::ApplicationModel::Calls::Background::PhoneLineProperties const*>(&lineProperty)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::Background::IPhoneNewVoicemailMessageTriggerDetails> : produce_base<D, llm::OS::ApplicationModel::Calls::Background::IPhoneNewVoicemailMessageTriggerDetails>
    {
        int32_t __stdcall get_LineId(llm::guid* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::guid>(this->shim().LineId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VoicemailCount(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<int32_t>(this->shim().VoicemailCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OperatorMessage(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().OperatorMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Calls::Background
{
    constexpr auto operator|(PhoneLineProperties const left, PhoneLineProperties const right) noexcept
    {
        return static_cast<PhoneLineProperties>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(PhoneLineProperties& left, PhoneLineProperties const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(PhoneLineProperties const left, PhoneLineProperties const right) noexcept
    {
        return static_cast<PhoneLineProperties>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(PhoneLineProperties& left, PhoneLineProperties const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(PhoneLineProperties const value) noexcept
    {
        return static_cast<PhoneLineProperties>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(PhoneLineProperties const left, PhoneLineProperties const right) noexcept
    {
        return static_cast<PhoneLineProperties>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(PhoneLineProperties& left, PhoneLineProperties const right) noexcept
    {
        left = left ^ right;
        return left;
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::Calls::Background::IPhoneCallBlockedTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Background::IPhoneCallOriginDataRequestTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallDismissedTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallNotificationTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Background::IPhoneLineChangedTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Background::IPhoneNewVoicemailMessageTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Background::PhoneCallBlockedTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Background::PhoneCallOriginDataRequestTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Background::PhoneIncomingCallDismissedTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Background::PhoneIncomingCallNotificationTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Background::PhoneLineChangedTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Background::PhoneNewVoicemailMessageTriggerDetails> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
