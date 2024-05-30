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
#ifndef LLM_OS_Security_Authentication_Web_Core_0_H
#define LLM_OS_Security_Authentication_Web_Core_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename K, typename V> struct __declspec(empty_bases) IMap;
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Security::Credentials
{
    struct WebAccount;
    struct WebAccountProvider;
}
LLM_EXPORT namespace llm:OS::System
{
    struct User;
}
LLM_EXPORT namespace llm:OS::Security::Authentication::Web::Core
{
    enum class FindAllWebAccountsStatus : int32_t
    {
        Success = 0,
        NotAllowedByProvider = 1,
        NotSupportedByProvider = 2,
        ProviderError = 3,
    };
    enum class WebTokenRequestPromptType : int32_t
    {
        Default = 0,
        ForceAuthentication = 1,
    };
    enum class WebTokenRequestStatus : int32_t
    {
        Success = 0,
        UserCancel = 1,
        AccountSwitch = 2,
        UserInteractionRequired = 3,
        AccountProviderNotAvailable = 4,
        ProviderError = 5,
    };
    struct IFindAllAccountsResult;
    struct IWebAccountEventArgs;
    struct IWebAccountMonitor;
    struct IWebAccountMonitor2;
    struct IWebAuthenticationCoreManagerStatics;
    struct IWebAuthenticationCoreManagerStatics2;
    struct IWebAuthenticationCoreManagerStatics3;
    struct IWebAuthenticationCoreManagerStatics4;
    struct IWebProviderError;
    struct IWebProviderErrorFactory;
    struct IWebTokenRequest;
    struct IWebTokenRequest2;
    struct IWebTokenRequest3;
    struct IWebTokenRequestFactory;
    struct IWebTokenRequestResult;
    struct IWebTokenResponse;
    struct IWebTokenResponseFactory;
    struct FindAllAccountsResult;
    struct WebAccountEventArgs;
    struct WebAccountMonitor;
    struct WebAuthenticationCoreManager;
    struct WebProviderError;
    struct WebTokenRequest;
    struct WebTokenRequestResult;
    struct WebTokenResponse;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Security::Authentication::Web::Core::IFindAllAccountsResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::IWebAccountEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor2>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics3>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics4>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::IWebProviderError>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::IWebProviderErrorFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::IWebTokenRequest>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::IWebTokenRequest2>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::IWebTokenRequest3>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::IWebTokenRequestFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::IWebTokenRequestResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::IWebTokenResponse>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::IWebTokenResponseFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::FindAllAccountsResult>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::WebAccountEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::WebAccountMonitor>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::WebAuthenticationCoreManager>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::WebProviderError>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::WebTokenRequest>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::WebTokenRequestResult>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::WebTokenResponse>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::FindAllWebAccountsStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::WebTokenRequestPromptType>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::Core::WebTokenRequestStatus>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::FindAllAccountsResult> = L"Windows.Security.Authentication.Web.Core.FindAllAccountsResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::WebAccountEventArgs> = L"Windows.Security.Authentication.Web.Core.WebAccountEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::WebAccountMonitor> = L"Windows.Security.Authentication.Web.Core.WebAccountMonitor";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::WebAuthenticationCoreManager> = L"Windows.Security.Authentication.Web.Core.WebAuthenticationCoreManager";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::WebProviderError> = L"Windows.Security.Authentication.Web.Core.WebProviderError";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::WebTokenRequest> = L"Windows.Security.Authentication.Web.Core.WebTokenRequest";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::WebTokenRequestResult> = L"Windows.Security.Authentication.Web.Core.WebTokenRequestResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::WebTokenResponse> = L"Windows.Security.Authentication.Web.Core.WebTokenResponse";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::FindAllWebAccountsStatus> = L"Windows.Security.Authentication.Web.Core.FindAllWebAccountsStatus";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::WebTokenRequestPromptType> = L"Windows.Security.Authentication.Web.Core.WebTokenRequestPromptType";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::WebTokenRequestStatus> = L"Windows.Security.Authentication.Web.Core.WebTokenRequestStatus";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::IFindAllAccountsResult> = L"Windows.Security.Authentication.Web.Core.IFindAllAccountsResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::IWebAccountEventArgs> = L"Windows.Security.Authentication.Web.Core.IWebAccountEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor> = L"Windows.Security.Authentication.Web.Core.IWebAccountMonitor";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor2> = L"Windows.Security.Authentication.Web.Core.IWebAccountMonitor2";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics> = L"Windows.Security.Authentication.Web.Core.IWebAuthenticationCoreManagerStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics2> = L"Windows.Security.Authentication.Web.Core.IWebAuthenticationCoreManagerStatics2";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics3> = L"Windows.Security.Authentication.Web.Core.IWebAuthenticationCoreManagerStatics3";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics4> = L"Windows.Security.Authentication.Web.Core.IWebAuthenticationCoreManagerStatics4";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::IWebProviderError> = L"Windows.Security.Authentication.Web.Core.IWebProviderError";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::IWebProviderErrorFactory> = L"Windows.Security.Authentication.Web.Core.IWebProviderErrorFactory";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::IWebTokenRequest> = L"Windows.Security.Authentication.Web.Core.IWebTokenRequest";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::IWebTokenRequest2> = L"Windows.Security.Authentication.Web.Core.IWebTokenRequest2";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::IWebTokenRequest3> = L"Windows.Security.Authentication.Web.Core.IWebTokenRequest3";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::IWebTokenRequestFactory> = L"Windows.Security.Authentication.Web.Core.IWebTokenRequestFactory";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::IWebTokenRequestResult> = L"Windows.Security.Authentication.Web.Core.IWebTokenRequestResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::IWebTokenResponse> = L"Windows.Security.Authentication.Web.Core.IWebTokenResponse";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::Core::IWebTokenResponseFactory> = L"Windows.Security.Authentication.Web.Core.IWebTokenResponseFactory";
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::Core::IFindAllAccountsResult>{ 0xA5812B5D,0xB72E,0x420C,{ 0x86,0xAB,0xAA,0xC0,0xD7,0xB7,0x26,0x1F } }; // A5812B5D-B72E-420C-86AB-AAC0D7B7261F
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::Core::IWebAccountEventArgs>{ 0x6FB7037D,0x424E,0x44EC,{ 0x97,0x7C,0xEF,0x24,0x15,0x46,0x2A,0x5A } }; // 6FB7037D-424E-44EC-977C-EF2415462A5A
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor>{ 0x7445F5FD,0xAA9D,0x4619,{ 0x8D,0x5D,0xC1,0x38,0xA4,0xED,0xE3,0xE5 } }; // 7445F5FD-AA9D-4619-8D5D-C138A4EDE3E5
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor2>{ 0xA7ADC1F8,0x24B8,0x4F01,{ 0x9A,0xE5,0x24,0x54,0x5E,0x71,0x23,0x3A } }; // A7ADC1F8-24B8-4F01-9AE5-24545E71233A
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics>{ 0x6ACA7C92,0xA581,0x4479,{ 0x9C,0x10,0x75,0x2E,0xFF,0x44,0xFD,0x34 } }; // 6ACA7C92-A581-4479-9C10-752EFF44FD34
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics2>{ 0xF584184A,0x8B57,0x4820,{ 0xB6,0xA4,0x70,0xA5,0xB6,0xFC,0xF4,0x4A } }; // F584184A-8B57-4820-B6A4-70A5B6FCF44A
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics3>{ 0x2404EEB2,0x8924,0x4D93,{ 0xAB,0x3A,0x99,0x68,0x8B,0x41,0x9D,0x56 } }; // 2404EEB2-8924-4D93-AB3A-99688B419D56
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics4>{ 0x54E633FE,0x96E0,0x41E8,{ 0x98,0x32,0x12,0x98,0x89,0x7C,0x2A,0xAF } }; // 54E633FE-96E0-41E8-9832-1298897C2AAF
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::Core::IWebProviderError>{ 0xDB191BB1,0x50C5,0x4809,{ 0x8D,0xCA,0x09,0xC9,0x94,0x10,0x24,0x5C } }; // DB191BB1-50C5-4809-8DCA-09C99410245C
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::Core::IWebProviderErrorFactory>{ 0xE3C40A2D,0x89EF,0x4E37,{ 0x84,0x7F,0xA8,0xB9,0xD5,0xA3,0x29,0x10 } }; // E3C40A2D-89EF-4E37-847F-A8B9D5A32910
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::Core::IWebTokenRequest>{ 0xB77B4D68,0xADCB,0x4673,{ 0xB3,0x64,0x0C,0xF7,0xB3,0x5C,0xAF,0x97 } }; // B77B4D68-ADCB-4673-B364-0CF7B35CAF97
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::Core::IWebTokenRequest2>{ 0xD700C079,0x30C8,0x4397,{ 0x96,0x54,0x96,0x1C,0x3B,0xE8,0xB8,0x55 } }; // D700C079-30C8-4397-9654-961C3BE8B855
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::Core::IWebTokenRequest3>{ 0x5A755B51,0x3BB1,0x41A5,{ 0xA6,0x3D,0x90,0xBC,0x32,0xC7,0xDB,0x9A } }; // 5A755B51-3BB1-41A5-A63D-90BC32C7DB9A
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::Core::IWebTokenRequestFactory>{ 0x6CF2141C,0x0FF0,0x4C67,{ 0xB8,0x4F,0x99,0xDD,0xBE,0x4A,0x72,0xC9 } }; // 6CF2141C-0FF0-4C67-B84F-99DDBE4A72C9
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::Core::IWebTokenRequestResult>{ 0xC12A8305,0xD1F8,0x4483,{ 0x8D,0x54,0x38,0xFE,0x29,0x27,0x84,0xFF } }; // C12A8305-D1F8-4483-8D54-38FE292784FF
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::Core::IWebTokenResponse>{ 0x67A7C5CA,0x83F6,0x44C6,{ 0xA3,0xB1,0x0E,0xB6,0x9E,0x41,0xFA,0x8A } }; // 67A7C5CA-83F6-44C6-A3B1-0EB69E41FA8A
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::Core::IWebTokenResponseFactory>{ 0xAB6BF7F8,0x5450,0x4EF6,{ 0x97,0xF7,0x05,0x2B,0x04,0x31,0xC0,0xF0 } }; // AB6BF7F8-5450-4EF6-97F7-052B0431C0F0
    template <> struct default_interface<llm:OS::Security::Authentication::Web::Core::FindAllAccountsResult>{ using type = llm:OS::Security::Authentication::Web::Core::IFindAllAccountsResult; };
    template <> struct default_interface<llm:OS::Security::Authentication::Web::Core::WebAccountEventArgs>{ using type = llm:OS::Security::Authentication::Web::Core::IWebAccountEventArgs; };
    template <> struct default_interface<llm:OS::Security::Authentication::Web::Core::WebAccountMonitor>{ using type = llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor; };
    template <> struct default_interface<llm:OS::Security::Authentication::Web::Core::WebProviderError>{ using type = llm:OS::Security::Authentication::Web::Core::IWebProviderError; };
    template <> struct default_interface<llm:OS::Security::Authentication::Web::Core::WebTokenRequest>{ using type = llm:OS::Security::Authentication::Web::Core::IWebTokenRequest; };
    template <> struct default_interface<llm:OS::Security::Authentication::Web::Core::WebTokenRequestResult>{ using type = llm:OS::Security::Authentication::Web::Core::IWebTokenRequestResult; };
    template <> struct default_interface<llm:OS::Security::Authentication::Web::Core::WebTokenResponse>{ using type = llm:OS::Security::Authentication::Web::Core::IWebTokenResponse; };
    template <> struct abi<llm:OS::Security::Authentication::Web::Core::IFindAllAccountsResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Accounts(void**) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ProviderError(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::Core::IWebAccountEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Account(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_Updated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Updated(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Removed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Removed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_DefaultSignInAccountChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_DefaultSignInAccountChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_AccountPictureUpdated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AccountPictureUpdated(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetTokenSilentlyAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetTokenSilentlyWithWebAccountAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestTokenAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestTokenWithWebAccountAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindAccountAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindAccountProviderAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindAccountProviderWithAuthorityAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FindAccountProviderWithAuthorityForUserAsync(void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWebAccountMonitor(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FindAllAccountsAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindAllAccountsWithClientIdAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindSystemAccountProviderAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindSystemAccountProviderWithAuthorityAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindSystemAccountProviderWithAuthorityForUserAsync(void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::Core::IWebProviderError>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ErrorCode(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ErrorMessage(void**) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::Core::IWebProviderErrorFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(uint32_t, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::Core::IWebTokenRequest>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_WebAccountProvider(void**) noexcept = 0;
            virtual int32_t __stdcall get_Scope(void**) noexcept = 0;
            virtual int32_t __stdcall get_ClientId(void**) noexcept = 0;
            virtual int32_t __stdcall get_PromptType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::Core::IWebTokenRequest2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AppProperties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::Core::IWebTokenRequest3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CorrelationId(void**) noexcept = 0;
            virtual int32_t __stdcall put_CorrelationId(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::Core::IWebTokenRequestFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithPromptType(void*, void*, void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithProvider(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithScope(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::Core::IWebTokenRequestResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ResponseData(void**) noexcept = 0;
            virtual int32_t __stdcall get_ResponseStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ResponseError(void**) noexcept = 0;
            virtual int32_t __stdcall InvalidateCacheAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::Core::IWebTokenResponse>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Token(void**) noexcept = 0;
            virtual int32_t __stdcall get_ProviderError(void**) noexcept = 0;
            virtual int32_t __stdcall get_WebAccount(void**) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::Core::IWebTokenResponseFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWithToken(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithTokenAndAccount(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithTokenAccountAndError(void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_Core_IFindAllAccountsResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Security::Credentials::WebAccount>) Accounts() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Web::Core::FindAllWebAccountsStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Web::Core::WebProviderError) ProviderError() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::Core::IFindAllAccountsResult>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_Core_IFindAllAccountsResult<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_Core_IWebAccountEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Credentials::WebAccount) Account() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::Core::IWebAccountEventArgs>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_Core_IWebAccountEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_Core_IWebAccountMonitor
    {
        LLM_IMPL_AUTO(llm::event_token) Updated(llm:OS::Foundation::TypedEventHandler<llm:OS::Security::Authentication::Web::Core::WebAccountMonitor, llm:OS::Security::Authentication::Web::Core::WebAccountEventArgs> const& handler) const;
        using Updated_revoker = impl::event_revoker<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor, &impl::abi_t<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor>::remove_Updated>;
        [[nodiscard]] Updated_revoker Updated(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Security::Authentication::Web::Core::WebAccountMonitor, llm:OS::Security::Authentication::Web::Core::WebAccountEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Updated(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Removed(llm:OS::Foundation::TypedEventHandler<llm:OS::Security::Authentication::Web::Core::WebAccountMonitor, llm:OS::Security::Authentication::Web::Core::WebAccountEventArgs> const& handler) const;
        using Removed_revoker = impl::event_revoker<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor, &impl::abi_t<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor>::remove_Removed>;
        [[nodiscard]] Removed_revoker Removed(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Security::Authentication::Web::Core::WebAccountMonitor, llm:OS::Security::Authentication::Web::Core::WebAccountEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Removed(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) DefaultSignInAccountChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Security::Authentication::Web::Core::WebAccountMonitor, llm:OS::Foundation::IInspectable> const& handler) const;
        using DefaultSignInAccountChanged_revoker = impl::event_revoker<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor, &impl::abi_t<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor>::remove_DefaultSignInAccountChanged>;
        [[nodiscard]] DefaultSignInAccountChanged_revoker DefaultSignInAccountChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Security::Authentication::Web::Core::WebAccountMonitor, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) DefaultSignInAccountChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_Core_IWebAccountMonitor<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_Core_IWebAccountMonitor2
    {
        LLM_IMPL_AUTO(llm::event_token) AccountPictureUpdated(llm:OS::Foundation::TypedEventHandler<llm:OS::Security::Authentication::Web::Core::WebAccountMonitor, llm:OS::Security::Authentication::Web::Core::WebAccountEventArgs> const& handler) const;
        using AccountPictureUpdated_revoker = impl::event_revoker<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor2, &impl::abi_t<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor2>::remove_AccountPictureUpdated>;
        [[nodiscard]] AccountPictureUpdated_revoker AccountPictureUpdated(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Security::Authentication::Web::Core::WebAccountMonitor, llm:OS::Security::Authentication::Web::Core::WebAccountEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) AccountPictureUpdated(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor2>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_Core_IWebAccountMonitor2<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_Core_IWebAuthenticationCoreManagerStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Web::Core::WebTokenRequestResult>) GetTokenSilentlyAsync(llm:OS::Security::Authentication::Web::Core::WebTokenRequest const& request) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Web::Core::WebTokenRequestResult>) GetTokenSilentlyAsync(llm:OS::Security::Authentication::Web::Core::WebTokenRequest const& request, llm:OS::Security::Credentials::WebAccount const& webAccount) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Web::Core::WebTokenRequestResult>) RequestTokenAsync(llm:OS::Security::Authentication::Web::Core::WebTokenRequest const& request) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Web::Core::WebTokenRequestResult>) RequestTokenAsync(llm:OS::Security::Authentication::Web::Core::WebTokenRequest const& request, llm:OS::Security::Credentials::WebAccount const& webAccount) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Credentials::WebAccount>) FindAccountAsync(llm:OS::Security::Credentials::WebAccountProvider const& provider, param::hstring const& webAccountId) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Credentials::WebAccountProvider>) FindAccountProviderAsync(param::hstring const& webAccountProviderId) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Credentials::WebAccountProvider>) FindAccountProviderAsync(param::hstring const& webAccountProviderId, param::hstring const& authority) const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_Core_IWebAuthenticationCoreManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_Core_IWebAuthenticationCoreManagerStatics2
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Credentials::WebAccountProvider>) FindAccountProviderAsync(param::hstring const& webAccountProviderId, param::hstring const& authority, llm:OS::System::User const& user) const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics2>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_Core_IWebAuthenticationCoreManagerStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_Core_IWebAuthenticationCoreManagerStatics3
    {
        LLM_IMPL_AUTO(llm:OS::Security::Authentication::Web::Core::WebAccountMonitor) CreateWebAccountMonitor(param::iterable<llm:OS::Security::Credentials::WebAccount> const& webAccounts) const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics3>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_Core_IWebAuthenticationCoreManagerStatics3<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_Core_IWebAuthenticationCoreManagerStatics4
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Web::Core::FindAllAccountsResult>) FindAllAccountsAsync(llm:OS::Security::Credentials::WebAccountProvider const& provider) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Web::Core::FindAllAccountsResult>) FindAllAccountsAsync(llm:OS::Security::Credentials::WebAccountProvider const& provider, param::hstring const& clientId) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Credentials::WebAccountProvider>) FindSystemAccountProviderAsync(param::hstring const& webAccountProviderId) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Credentials::WebAccountProvider>) FindSystemAccountProviderAsync(param::hstring const& webAccountProviderId, param::hstring const& authority) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Credentials::WebAccountProvider>) FindSystemAccountProviderAsync(param::hstring const& webAccountProviderId, param::hstring const& authority, llm:OS::System::User const& user) const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics4>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_Core_IWebAuthenticationCoreManagerStatics4<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_Core_IWebProviderError
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) ErrorCode() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ErrorMessage() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IMap<hstring, hstring>) Properties() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::Core::IWebProviderError>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_Core_IWebProviderError<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_Core_IWebProviderErrorFactory
    {
        LLM_IMPL_AUTO(llm:OS::Security::Authentication::Web::Core::WebProviderError) Create(uint32_t errorCode, param::hstring const& errorMessage) const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::Core::IWebProviderErrorFactory>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_Core_IWebProviderErrorFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_Core_IWebTokenRequest
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Credentials::WebAccountProvider) WebAccountProvider() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Scope() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ClientId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Web::Core::WebTokenRequestPromptType) PromptType() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IMap<hstring, hstring>) Properties() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::Core::IWebTokenRequest>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_Core_IWebTokenRequest<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_Core_IWebTokenRequest2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IMap<hstring, hstring>) AppProperties() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::Core::IWebTokenRequest2>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_Core_IWebTokenRequest2<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_Core_IWebTokenRequest3
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CorrelationId() const;
        LLM_IMPL_AUTO(void) CorrelationId(param::hstring const& value) const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::Core::IWebTokenRequest3>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_Core_IWebTokenRequest3<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_Core_IWebTokenRequestFactory
    {
        LLM_IMPL_AUTO(llm:OS::Security::Authentication::Web::Core::WebTokenRequest) Create(llm:OS::Security::Credentials::WebAccountProvider const& provider, param::hstring const& scope, param::hstring const& clientId) const;
        LLM_IMPL_AUTO(llm:OS::Security::Authentication::Web::Core::WebTokenRequest) CreateWithPromptType(llm:OS::Security::Credentials::WebAccountProvider const& provider, param::hstring const& scope, param::hstring const& clientId, llm:OS::Security::Authentication::Web::Core::WebTokenRequestPromptType const& promptType) const;
        LLM_IMPL_AUTO(llm:OS::Security::Authentication::Web::Core::WebTokenRequest) CreateWithProvider(llm:OS::Security::Credentials::WebAccountProvider const& provider) const;
        LLM_IMPL_AUTO(llm:OS::Security::Authentication::Web::Core::WebTokenRequest) CreateWithScope(llm:OS::Security::Credentials::WebAccountProvider const& provider, param::hstring const& scope) const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::Core::IWebTokenRequestFactory>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_Core_IWebTokenRequestFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_Core_IWebTokenRequestResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Security::Authentication::Web::Core::WebTokenResponse>) ResponseData() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Web::Core::WebTokenRequestStatus) ResponseStatus() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Web::Core::WebProviderError) ResponseError() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) InvalidateCacheAsync() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::Core::IWebTokenRequestResult>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_Core_IWebTokenRequestResult<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_Core_IWebTokenResponse
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Token() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Web::Core::WebProviderError) ProviderError() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Credentials::WebAccount) WebAccount() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IMap<hstring, hstring>) Properties() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::Core::IWebTokenResponse>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_Core_IWebTokenResponse<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_Core_IWebTokenResponseFactory
    {
        LLM_IMPL_AUTO(llm:OS::Security::Authentication::Web::Core::WebTokenResponse) CreateWithToken(param::hstring const& token) const;
        LLM_IMPL_AUTO(llm:OS::Security::Authentication::Web::Core::WebTokenResponse) CreateWithTokenAndAccount(param::hstring const& token, llm:OS::Security::Credentials::WebAccount const& webAccount) const;
        LLM_IMPL_AUTO(llm:OS::Security::Authentication::Web::Core::WebTokenResponse) CreateWithTokenAccountAndError(param::hstring const& token, llm:OS::Security::Credentials::WebAccount const& webAccount, llm:OS::Security::Authentication::Web::Core::WebProviderError const& error) const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::Core::IWebTokenResponseFactory>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_Core_IWebTokenResponseFactory<D>;
    };
}
#endif
