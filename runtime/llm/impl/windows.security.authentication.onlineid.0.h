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
#ifndef LLM_OS_Security_Authentication_OnlineId_0_H
#define LLM_OS_Security_Authentication_OnlineId_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct HResult;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::System
{
    struct User;
}
LLM_EXPORT namespace llm:OS::Security::Authentication::OnlineId
{
    enum class CredentialPromptType : int32_t
    {
        PromptIfNeeded = 0,
        RetypeCredentials = 1,
        DoNotPrompt = 2,
    };
    enum class OnlineIdSystemTicketStatus : int32_t
    {
        Success = 0,
        Error = 1,
        ServiceConnectionError = 2,
    };
    struct IOnlineIdAuthenticator;
    struct IOnlineIdServiceTicket;
    struct IOnlineIdServiceTicketRequest;
    struct IOnlineIdServiceTicketRequestFactory;
    struct IOnlineIdSystemAuthenticatorForUser;
    struct IOnlineIdSystemAuthenticatorStatics;
    struct IOnlineIdSystemIdentity;
    struct IOnlineIdSystemTicketResult;
    struct IUserIdentity;
    struct OnlineIdAuthenticator;
    struct OnlineIdServiceTicket;
    struct OnlineIdServiceTicketRequest;
    struct OnlineIdSystemAuthenticator;
    struct OnlineIdSystemAuthenticatorForUser;
    struct OnlineIdSystemIdentity;
    struct OnlineIdSystemTicketResult;
    struct SignOutUserOperation;
    struct UserAuthenticationOperation;
    struct UserIdentity;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicket>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequestFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemIdentity>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::IUserIdentity>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::OnlineIdAuthenticator>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::OnlineIdServiceTicket>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::OnlineIdSystemAuthenticator>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::OnlineIdSystemAuthenticatorForUser>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::OnlineIdSystemIdentity>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::OnlineIdSystemTicketResult>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::SignOutUserOperation>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::UserAuthenticationOperation>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::UserIdentity>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::CredentialPromptType>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::OnlineId::OnlineIdSystemTicketStatus>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::OnlineIdAuthenticator> = L"Windows.Security.Authentication.OnlineId.OnlineIdAuthenticator";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::OnlineIdServiceTicket> = L"Windows.Security.Authentication.OnlineId.OnlineIdServiceTicket";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest> = L"Windows.Security.Authentication.OnlineId.OnlineIdServiceTicketRequest";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::OnlineIdSystemAuthenticator> = L"Windows.Security.Authentication.OnlineId.OnlineIdSystemAuthenticator";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::OnlineIdSystemAuthenticatorForUser> = L"Windows.Security.Authentication.OnlineId.OnlineIdSystemAuthenticatorForUser";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::OnlineIdSystemIdentity> = L"Windows.Security.Authentication.OnlineId.OnlineIdSystemIdentity";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::OnlineIdSystemTicketResult> = L"Windows.Security.Authentication.OnlineId.OnlineIdSystemTicketResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::SignOutUserOperation> = L"Windows.Security.Authentication.OnlineId.SignOutUserOperation";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::UserAuthenticationOperation> = L"Windows.Security.Authentication.OnlineId.UserAuthenticationOperation";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::UserIdentity> = L"Windows.Security.Authentication.OnlineId.UserIdentity";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::CredentialPromptType> = L"Windows.Security.Authentication.OnlineId.CredentialPromptType";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::OnlineIdSystemTicketStatus> = L"Windows.Security.Authentication.OnlineId.OnlineIdSystemTicketStatus";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator> = L"Windows.Security.Authentication.OnlineId.IOnlineIdAuthenticator";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicket> = L"Windows.Security.Authentication.OnlineId.IOnlineIdServiceTicket";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest> = L"Windows.Security.Authentication.OnlineId.IOnlineIdServiceTicketRequest";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequestFactory> = L"Windows.Security.Authentication.OnlineId.IOnlineIdServiceTicketRequestFactory";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser> = L"Windows.Security.Authentication.OnlineId.IOnlineIdSystemAuthenticatorForUser";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorStatics> = L"Windows.Security.Authentication.OnlineId.IOnlineIdSystemAuthenticatorStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemIdentity> = L"Windows.Security.Authentication.OnlineId.IOnlineIdSystemIdentity";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult> = L"Windows.Security.Authentication.OnlineId.IOnlineIdSystemTicketResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::OnlineId::IUserIdentity> = L"Windows.Security.Authentication.OnlineId.IUserIdentity";
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator>{ 0xA003F58A,0x29AB,0x4817,{ 0xB8,0x84,0xD7,0x51,0x6D,0xAD,0x18,0xB9 } }; // A003F58A-29AB-4817-B884-D7516DAD18B9
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicket>{ 0xC95C547F,0xD781,0x4A94,{ 0xAC,0xB8,0xC5,0x98,0x74,0x23,0x8C,0x26 } }; // C95C547F-D781-4A94-ACB8-C59874238C26
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest>{ 0x297445D3,0xFB63,0x4135,{ 0x89,0x09,0x4E,0x35,0x4C,0x06,0x14,0x66 } }; // 297445D3-FB63-4135-8909-4E354C061466
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequestFactory>{ 0xBEBB0A08,0x9E73,0x4077,{ 0x96,0x14,0x08,0x61,0x4C,0x0B,0xC2,0x45 } }; // BEBB0A08-9E73-4077-9614-08614C0BC245
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser>{ 0x5798BEFB,0x1DE4,0x4186,{ 0xA2,0xE6,0xB5,0x63,0xF8,0x6A,0xAF,0x44 } }; // 5798BEFB-1DE4-4186-A2E6-B563F86AAF44
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorStatics>{ 0x85047792,0xF634,0x41E3,{ 0x96,0xA4,0x51,0x64,0xE9,0x02,0xC7,0x40 } }; // 85047792-F634-41E3-96A4-5164E902C740
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemIdentity>{ 0x743CD20D,0xB6CA,0x434D,{ 0x81,0x24,0x53,0xEA,0x12,0x68,0x53,0x07 } }; // 743CD20D-B6CA-434D-8124-53EA12685307
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult>{ 0xDB0A5FF8,0xB098,0x4ACD,{ 0x9D,0x13,0x9E,0x64,0x06,0x52,0xB5,0xB6 } }; // DB0A5FF8-B098-4ACD-9D13-9E640652B5B6
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::OnlineId::IUserIdentity>{ 0x2146D9CD,0x0742,0x4BE3,{ 0x8A,0x1C,0x7C,0x7A,0xE6,0x79,0xAA,0x88 } }; // 2146D9CD-0742-4BE3-8A1C-7C7AE679AA88
    template <> struct default_interface<llm:OS::Security::Authentication::OnlineId::OnlineIdAuthenticator>{ using type = llm:OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator; };
    template <> struct default_interface<llm:OS::Security::Authentication::OnlineId::OnlineIdServiceTicket>{ using type = llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicket; };
    template <> struct default_interface<llm:OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest>{ using type = llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest; };
    template <> struct default_interface<llm:OS::Security::Authentication::OnlineId::OnlineIdSystemAuthenticatorForUser>{ using type = llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser; };
    template <> struct default_interface<llm:OS::Security::Authentication::OnlineId::OnlineIdSystemIdentity>{ using type = llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemIdentity; };
    template <> struct default_interface<llm:OS::Security::Authentication::OnlineId::OnlineIdSystemTicketResult>{ using type = llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult; };
    template <> struct default_interface<llm:OS::Security::Authentication::OnlineId::SignOutUserOperation>{ using type = llm:OS::Foundation::IAsyncAction; };
    template <> struct default_interface<llm:OS::Security::Authentication::OnlineId::UserAuthenticationOperation>{ using type = llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::OnlineId::UserIdentity>; };
    template <> struct default_interface<llm:OS::Security::Authentication::OnlineId::UserIdentity>{ using type = llm:OS::Security::Authentication::OnlineId::IUserIdentity; };
    template <> struct abi<llm:OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall AuthenticateUserAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall AuthenticateUserAsyncAdvanced(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall SignOutUserAsync(void**) noexcept = 0;
            virtual int32_t __stdcall put_ApplicationId(llm::guid) noexcept = 0;
            virtual int32_t __stdcall get_ApplicationId(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall get_CanSignOut(bool*) noexcept = 0;
            virtual int32_t __stdcall get_AuthenticatedSafeCustomerId(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicket>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
            virtual int32_t __stdcall get_Request(void**) noexcept = 0;
            virtual int32_t __stdcall get_ErrorCode(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Service(void**) noexcept = 0;
            virtual int32_t __stdcall get_Policy(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequestFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateOnlineIdServiceTicketRequest(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateOnlineIdServiceTicketRequestAdvanced(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetTicketAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall put_ApplicationId(llm::guid) noexcept = 0;
            virtual int32_t __stdcall get_ApplicationId(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall get_User(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Default(void**) noexcept = 0;
            virtual int32_t __stdcall GetForUser(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemIdentity>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Ticket(void**) noexcept = 0;
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Identity(void**) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::OnlineId::IUserIdentity>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Tickets(void**) noexcept = 0;
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_SafeCustomerId(void**) noexcept = 0;
            virtual int32_t __stdcall get_SignInName(void**) noexcept = 0;
            virtual int32_t __stdcall get_FirstName(void**) noexcept = 0;
            virtual int32_t __stdcall get_LastName(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsBetaAccount(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsConfirmedPC(bool*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_OnlineId_IOnlineIdAuthenticator
    {
        LLM_IMPL_AUTO(llm:OS::Security::Authentication::OnlineId::UserAuthenticationOperation) AuthenticateUserAsync(llm:OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest const& request) const;
        LLM_IMPL_AUTO(llm:OS::Security::Authentication::OnlineId::UserAuthenticationOperation) AuthenticateUserAsync(param::iterable<llm:OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest> const& requests, llm:OS::Security::Authentication::OnlineId::CredentialPromptType const& credentialPromptType) const;
        LLM_IMPL_AUTO(llm:OS::Security::Authentication::OnlineId::SignOutUserOperation) SignOutUserAsync() const;
        LLM_IMPL_AUTO(void) ApplicationId(llm::guid const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) ApplicationId() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) CanSignOut() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AuthenticatedSafeCustomerId() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_OnlineId_IOnlineIdAuthenticator<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_OnlineId_IOnlineIdServiceTicket
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Value() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest) Request() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) ErrorCode() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicket>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_OnlineId_IOnlineIdServiceTicket<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_OnlineId_IOnlineIdServiceTicketRequest
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Service() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Policy() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_OnlineId_IOnlineIdServiceTicketRequest<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_OnlineId_IOnlineIdServiceTicketRequestFactory
    {
        LLM_IMPL_AUTO(llm:OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest) CreateOnlineIdServiceTicketRequest(param::hstring const& service, param::hstring const& policy) const;
        LLM_IMPL_AUTO(llm:OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest) CreateOnlineIdServiceTicketRequestAdvanced(param::hstring const& service) const;
    };
    template <> struct consume<llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequestFactory>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_OnlineId_IOnlineIdServiceTicketRequestFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemAuthenticatorForUser
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::OnlineId::OnlineIdSystemTicketResult>) GetTicketAsync(llm:OS::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest const& request) const;
        LLM_IMPL_AUTO(void) ApplicationId(llm::guid const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) ApplicationId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::User) User() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemAuthenticatorForUser<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemAuthenticatorStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::OnlineId::OnlineIdSystemAuthenticatorForUser) Default() const;
        LLM_IMPL_AUTO(llm:OS::Security::Authentication::OnlineId::OnlineIdSystemAuthenticatorForUser) GetForUser(llm:OS::System::User const& user) const;
    };
    template <> struct consume<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorStatics>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemAuthenticatorStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemIdentity
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::OnlineId::OnlineIdServiceTicket) Ticket() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemIdentity>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemIdentity<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemTicketResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::OnlineId::OnlineIdSystemIdentity) Identity() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::OnlineId::OnlineIdSystemTicketStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_OnlineId_IOnlineIdSystemTicketResult<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_OnlineId_IUserIdentity
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Security::Authentication::OnlineId::OnlineIdServiceTicket>) Tickets() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SafeCustomerId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SignInName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) FirstName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) LastName() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsBetaAccount() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsConfirmedPC() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::OnlineId::IUserIdentity>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_OnlineId_IUserIdentity<D>;
    };
}
#endif
