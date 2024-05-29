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
#ifndef LLM_OS_ApplicationModel_ExtendedExecution_Foreground_0_H
#define LLM_OS_ApplicationModel_ExtendedExecution_Foreground_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::ExtendedExecution::Foreground
{
    enum class ExtendedExecutionForegroundReason : int32_t
    {
        Unspecified = 0,
        SavingData = 1,
        BackgroundAudio = 2,
        Unconstrained = 3,
    };
    enum class ExtendedExecutionForegroundResult : int32_t
    {
        Allowed = 0,
        Denied = 1,
    };
    enum class ExtendedExecutionForegroundRevokedReason : int32_t
    {
        Resumed = 0,
        SystemPolicy = 1,
    };
    struct IExtendedExecutionForegroundRevokedEventArgs;
    struct IExtendedExecutionForegroundSession;
    struct ExtendedExecutionForegroundRevokedEventArgs;
    struct ExtendedExecutionForegroundSession;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundSession>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedReason>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs> = L"Windows.ApplicationModel.ExtendedExecution.Foreground.ExtendedExecutionForegroundRevokedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundSession> = L"Windows.ApplicationModel.ExtendedExecution.Foreground.ExtendedExecutionForegroundSession";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason> = L"Windows.ApplicationModel.ExtendedExecution.Foreground.ExtendedExecutionForegroundReason";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult> = L"Windows.ApplicationModel.ExtendedExecution.Foreground.ExtendedExecutionForegroundResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedReason> = L"Windows.ApplicationModel.ExtendedExecution.Foreground.ExtendedExecutionForegroundRevokedReason";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs> = L"Windows.ApplicationModel.ExtendedExecution.Foreground.IExtendedExecutionForegroundRevokedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession> = L"Windows.ApplicationModel.ExtendedExecution.Foreground.IExtendedExecutionForegroundSession";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs>{ 0xB07CD940,0x9557,0xAEA4,{ 0x2C,0x99,0xBD,0xD5,0x6D,0x9B,0xE4,0x61 } }; // B07CD940-9557-AEA4-2C99-BDD56D9BE461
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>{ 0xFBF440E1,0x9D10,0x4201,{ 0xB0,0x1E,0xC8,0x32,0x75,0x29,0x6F,0x2E } }; // FBF440E1-9D10-4201-B01E-C83275296F2E
    template <> struct default_interface<llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs>{ using type = llm::OS::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundSession>{ using type = llm::OS::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession; };
    template <> struct abi<llm::OS::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Reason(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall put_Description(void*) noexcept = 0;
            virtual int32_t __stdcall add_Revoked(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Revoked(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall RequestExtensionAsync(void**) noexcept = 0;
            virtual int32_t __stdcall get_Reason(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Reason(int32_t) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ExtendedExecution_Foreground_IExtendedExecutionForegroundRevokedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedReason) Reason() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ExtendedExecution_Foreground_IExtendedExecutionForegroundRevokedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ExtendedExecution_Foreground_IExtendedExecutionForegroundSession
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        LLM_IMPL_AUTO(void) Description(param::hstring const& value) const;
        LLM_IMPL_AUTO(llm::event_token) Revoked(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs> const& handler) const;
        using Revoked_revoker = impl::event_revoker<llm::OS::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession, &impl::abi_t<llm::OS::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>::remove_Revoked>;
        [[nodiscard]] Revoked_revoker Revoked(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Revoked(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult>) RequestExtensionAsync() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason) Reason() const;
        LLM_IMPL_AUTO(void) Reason(llm::OS::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ExtendedExecution_Foreground_IExtendedExecutionForegroundSession<D>;
    };
}
#endif
