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
#ifndef LLM_OS_ApplicationModel_ExtendedExecution_0_H
#define LLM_OS_ApplicationModel_ExtendedExecution_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::ExtendedExecution
{
    enum class ExtendedExecutionReason : int32_t
    {
        Unspecified = 0,
        LocationTracking = 1,
        SavingData = 2,
    };
    enum class ExtendedExecutionResult : int32_t
    {
        Allowed = 0,
        Denied = 1,
    };
    enum class ExtendedExecutionRevokedReason : int32_t
    {
        Resumed = 0,
        SystemPolicy = 1,
    };
    struct IExtendedExecutionRevokedEventArgs;
    struct IExtendedExecutionSession;
    struct ExtendedExecutionRevokedEventArgs;
    struct ExtendedExecutionSession;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionRevokedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionRevokedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionSession>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionReason>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionResult>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionRevokedReason>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionRevokedEventArgs> = L"Windows.ApplicationModel.ExtendedExecution.ExtendedExecutionRevokedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionSession> = L"Windows.ApplicationModel.ExtendedExecution.ExtendedExecutionSession";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionReason> = L"Windows.ApplicationModel.ExtendedExecution.ExtendedExecutionReason";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionResult> = L"Windows.ApplicationModel.ExtendedExecution.ExtendedExecutionResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionRevokedReason> = L"Windows.ApplicationModel.ExtendedExecution.ExtendedExecutionRevokedReason";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionRevokedEventArgs> = L"Windows.ApplicationModel.ExtendedExecution.IExtendedExecutionRevokedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession> = L"Windows.ApplicationModel.ExtendedExecution.IExtendedExecutionSession";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionRevokedEventArgs>{ 0xBFBC9F16,0x63B5,0x4C0B,{ 0xAA,0xD6,0x82,0x8A,0xF5,0x37,0x3E,0xC3 } }; // BFBC9F16-63B5-4C0B-AAD6-828AF5373EC3
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession>{ 0xAF908A2D,0x118B,0x48F1,{ 0x93,0x08,0x0C,0x4F,0xC4,0x1E,0x20,0x0F } }; // AF908A2D-118B-48F1-9308-0C4FC41E200F
    template <> struct default_interface<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionRevokedEventArgs>{ using type = llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionRevokedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionSession>{ using type = llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession; };
    template <> struct abi<llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionRevokedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Reason(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Reason(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Reason(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall put_Description(void*) noexcept = 0;
            virtual int32_t __stdcall get_PercentProgress(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_PercentProgress(uint32_t) noexcept = 0;
            virtual int32_t __stdcall add_Revoked(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Revoked(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall RequestExtensionAsync(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ExtendedExecution_IExtendedExecutionRevokedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionRevokedReason) Reason() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionRevokedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ExtendedExecution_IExtendedExecutionRevokedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ExtendedExecution_IExtendedExecutionSession
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionReason) Reason() const;
        LLM_IMPL_AUTO(void) Reason(llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionReason const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        LLM_IMPL_AUTO(void) Description(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) PercentProgress() const;
        LLM_IMPL_AUTO(void) PercentProgress(uint32_t value) const;
        LLM_IMPL_AUTO(llm::event_token) Revoked(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionRevokedEventArgs> const& handler) const;
        using Revoked_revoker = impl::event_revoker<llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession, &impl::abi_t<llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession>::remove_Revoked>;
        [[nodiscard]] Revoked_revoker Revoked(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionRevokedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Revoked(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionResult>) RequestExtensionAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ExtendedExecution_IExtendedExecutionSession<D>;
    };
}
#endif
