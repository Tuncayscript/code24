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
#ifndef LLM_OS_Management_Policies_0_H
#define LLM_OS_Management_Policies_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IBuffer;
}
LLM_EXPORT namespace llm:OS::System
{
    struct User;
}
LLM_EXPORT namespace llm:OS::Management::Policies
{
    enum class NamedPolicyKind : int32_t
    {
        Invalid = 0,
        Binary = 1,
        Boolean = 2,
        Int32 = 3,
        Int64 = 4,
        String = 5,
    };
    struct INamedPolicyData;
    struct INamedPolicyStatics;
    struct NamedPolicy;
    struct NamedPolicyData;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Management::Policies::INamedPolicyData>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Policies::INamedPolicyStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Policies::NamedPolicy>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Policies::NamedPolicyData>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Policies::NamedPolicyKind>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Management::Policies::NamedPolicy> = L"Windows.Management.Policies.NamedPolicy";
    template <> inline constexpr auto& name_v<llm:OS::Management::Policies::NamedPolicyData> = L"Windows.Management.Policies.NamedPolicyData";
    template <> inline constexpr auto& name_v<llm:OS::Management::Policies::NamedPolicyKind> = L"Windows.Management.Policies.NamedPolicyKind";
    template <> inline constexpr auto& name_v<llm:OS::Management::Policies::INamedPolicyData> = L"Windows.Management.Policies.INamedPolicyData";
    template <> inline constexpr auto& name_v<llm:OS::Management::Policies::INamedPolicyStatics> = L"Windows.Management.Policies.INamedPolicyStatics";
    template <> inline constexpr guid guid_v<llm:OS::Management::Policies::INamedPolicyData>{ 0x38DCB198,0x95AC,0x4077,{ 0xA6,0x43,0x80,0x78,0xCA,0xE2,0x64,0x00 } }; // 38DCB198-95AC-4077-A643-8078CAE26400
    template <> inline constexpr guid guid_v<llm:OS::Management::Policies::INamedPolicyStatics>{ 0x7F793BE7,0x76C4,0x4058,{ 0x8C,0xAD,0x67,0x66,0x2C,0xD0,0x5F,0x0D } }; // 7F793BE7-76C4-4058-8CAD-67662CD05F0D
    template <> struct default_interface<llm:OS::Management::Policies::NamedPolicyData>{ using type = llm:OS::Management::Policies::INamedPolicyData; };
    template <> struct abi<llm:OS::Management::Policies::INamedPolicyData>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Area(void**) noexcept = 0;
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_IsManaged(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsUserPolicy(bool*) noexcept = 0;
            virtual int32_t __stdcall get_User(void**) noexcept = 0;
            virtual int32_t __stdcall GetBoolean(bool*) noexcept = 0;
            virtual int32_t __stdcall GetBinary(void**) noexcept = 0;
            virtual int32_t __stdcall GetInt32(int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetInt64(int64_t*) noexcept = 0;
            virtual int32_t __stdcall GetString(void**) noexcept = 0;
            virtual int32_t __stdcall add_Changed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Changed(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Policies::INamedPolicyStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetPolicyFromPath(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetPolicyFromPathForUser(void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Management_Policies_INamedPolicyData
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Area() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Management::Policies::NamedPolicyKind) Kind() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsManaged() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsUserPolicy() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::User) User() const;
        LLM_IMPL_AUTO(bool) GetBoolean() const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) GetBinary() const;
        LLM_IMPL_AUTO(int32_t) GetInt32() const;
        LLM_IMPL_AUTO(int64_t) GetInt64() const;
        LLM_IMPL_AUTO(hstring) GetString() const;
        LLM_IMPL_AUTO(llm::event_token) Changed(llm:OS::Foundation::TypedEventHandler<llm:OS::Management::Policies::NamedPolicyData, llm:OS::Foundation::IInspectable> const& changedHandler) const;
        using Changed_revoker = impl::event_revoker<llm:OS::Management::Policies::INamedPolicyData, &impl::abi_t<llm:OS::Management::Policies::INamedPolicyData>::remove_Changed>;
        [[nodiscard]] Changed_revoker Changed(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Management::Policies::NamedPolicyData, llm:OS::Foundation::IInspectable> const& changedHandler) const;
        LLM_IMPL_AUTO(void) Changed(llm::event_token const& cookie) const noexcept;
    };
    template <> struct consume<llm:OS::Management::Policies::INamedPolicyData>
    {
        template <typename D> using type = consume_Windows_Management_Policies_INamedPolicyData<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Policies_INamedPolicyStatics
    {
        LLM_IMPL_AUTO(llm:OS::Management::Policies::NamedPolicyData) GetPolicyFromPath(param::hstring const& area, param::hstring const& name) const;
        LLM_IMPL_AUTO(llm:OS::Management::Policies::NamedPolicyData) GetPolicyFromPathForUser(llm:OS::System::User const& user, param::hstring const& area, param::hstring const& name) const;
    };
    template <> struct consume<llm:OS::Management::Policies::INamedPolicyStatics>
    {
        template <typename D> using type = consume_Windows_Management_Policies_INamedPolicyStatics<D>;
    };
}
#endif
