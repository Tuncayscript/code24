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
#ifndef LLM_OS_Security_Authentication_Web_0_H
#define LLM_OS_Security_Authentication_Web_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    struct Uri;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    struct ValueSet;
}
LLM_EXPORT namespace llm:OS::Security::Authentication::Web
{
    enum class TokenBindingKeyType : int32_t
    {
        Rsa2048 = 0,
        EcdsaP256 = 1,
        AnyExisting = 2,
    };
    enum class WebAuthenticationOptions : uint32_t
    {
        None = 0,
        SilentMode = 0x1,
        UseTitle = 0x2,
        UseHttpPost = 0x4,
        UseCorporateNetwork = 0x8,
    };
    enum class WebAuthenticationStatus : int32_t
    {
        Success = 0,
        UserCancel = 1,
        ErrorHttp = 2,
    };
    struct IWebAuthenticationBrokerStatics;
    struct IWebAuthenticationBrokerStatics2;
    struct IWebAuthenticationResult;
    struct WebAuthenticationBroker;
    struct WebAuthenticationResult;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::IWebAuthenticationResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::WebAuthenticationBroker>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::WebAuthenticationResult>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::TokenBindingKeyType>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::WebAuthenticationOptions>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::Web::WebAuthenticationStatus>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::WebAuthenticationBroker> = L"Windows.Security.Authentication.Web.WebAuthenticationBroker";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::WebAuthenticationResult> = L"Windows.Security.Authentication.Web.WebAuthenticationResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::TokenBindingKeyType> = L"Windows.Security.Authentication.Web.TokenBindingKeyType";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::WebAuthenticationOptions> = L"Windows.Security.Authentication.Web.WebAuthenticationOptions";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::WebAuthenticationStatus> = L"Windows.Security.Authentication.Web.WebAuthenticationStatus";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics> = L"Windows.Security.Authentication.Web.IWebAuthenticationBrokerStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics2> = L"Windows.Security.Authentication.Web.IWebAuthenticationBrokerStatics2";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Web::IWebAuthenticationResult> = L"Windows.Security.Authentication.Web.IWebAuthenticationResult";
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics>{ 0x2F149F1A,0xE673,0x40B5,{ 0xBC,0x22,0x20,0x1A,0x68,0x64,0xA3,0x7B } }; // 2F149F1A-E673-40B5-BC22-201A6864A37B
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics2>{ 0x73CDFB9E,0x14E7,0x41DA,{ 0xA9,0x71,0xAA,0xF4,0x41,0x0B,0x62,0x1E } }; // 73CDFB9E-14E7-41DA-A971-AAF4410B621E
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Web::IWebAuthenticationResult>{ 0x64002B4B,0xEDE9,0x470A,{ 0xA5,0xCD,0x03,0x23,0xFA,0xF6,0xE2,0x62 } }; // 64002B4B-EDE9-470A-A5CD-0323FAF6E262
    template <> struct default_interface<llm:OS::Security::Authentication::Web::WebAuthenticationResult>{ using type = llm:OS::Security::Authentication::Web::IWebAuthenticationResult; };
    template <> struct abi<llm:OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall AuthenticateWithCallbackUriAsync(uint32_t, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall AuthenticateWithoutCallbackUriAsync(uint32_t, void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetCurrentApplicationCallbackUri(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall AuthenticateAndContinue(void*) noexcept = 0;
            virtual int32_t __stdcall AuthenticateWithCallbackUriAndContinue(void*, void*) noexcept = 0;
            virtual int32_t __stdcall AuthenticateWithCallbackUriContinuationDataAndOptionsAndContinue(void*, void*, void*, uint32_t) noexcept = 0;
            virtual int32_t __stdcall AuthenticateSilentlyAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall AuthenticateSilentlyWithOptionsAsync(void*, uint32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Web::IWebAuthenticationResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ResponseData(void**) noexcept = 0;
            virtual int32_t __stdcall get_ResponseStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ResponseErrorDetail(uint32_t*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_IWebAuthenticationBrokerStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Web::WebAuthenticationResult>) AuthenticateAsync(llm:OS::Security::Authentication::Web::WebAuthenticationOptions const& options, llm:OS::Foundation::Uri const& requestUri, llm:OS::Foundation::Uri const& callbackUri) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Web::WebAuthenticationResult>) AuthenticateAsync(llm:OS::Security::Authentication::Web::WebAuthenticationOptions const& options, llm:OS::Foundation::Uri const& requestUri) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Uri) GetCurrentApplicationCallbackUri() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_IWebAuthenticationBrokerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_IWebAuthenticationBrokerStatics2
    {
        LLM_IMPL_AUTO(void) AuthenticateAndContinue(llm:OS::Foundation::Uri const& requestUri) const;
        LLM_IMPL_AUTO(void) AuthenticateAndContinue(llm:OS::Foundation::Uri const& requestUri, llm:OS::Foundation::Uri const& callbackUri) const;
        LLM_IMPL_AUTO(void) AuthenticateAndContinue(llm:OS::Foundation::Uri const& requestUri, llm:OS::Foundation::Uri const& callbackUri, llm:OS::Foundation::Collections::ValueSet const& continuationData, llm:OS::Security::Authentication::Web::WebAuthenticationOptions const& options) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Web::WebAuthenticationResult>) AuthenticateSilentlyAsync(llm:OS::Foundation::Uri const& requestUri) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Web::WebAuthenticationResult>) AuthenticateSilentlyAsync(llm:OS::Foundation::Uri const& requestUri, llm:OS::Security::Authentication::Web::WebAuthenticationOptions const& options) const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics2>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_IWebAuthenticationBrokerStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Web_IWebAuthenticationResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ResponseData() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Web::WebAuthenticationStatus) ResponseStatus() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) ResponseErrorDetail() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Web::IWebAuthenticationResult>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Web_IWebAuthenticationResult<D>;
    };
}
#endif
