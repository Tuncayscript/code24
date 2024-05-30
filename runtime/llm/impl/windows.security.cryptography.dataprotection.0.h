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
#ifndef LLM_OS_Security_Cryptography_DataProtection_0_H
#define LLM_OS_Security_Cryptography_DataProtection_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IBuffer;
    struct IInputStream;
    struct IOutputStream;
}
LLM_EXPORT namespace llm:OS::Security::Cryptography::DataProtection
{
    struct IDataProtectionProvider;
    struct IDataProtectionProviderFactory;
    struct DataProtectionProvider;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Security::Cryptography::DataProtection::IDataProtectionProvider>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::DataProtection::IDataProtectionProviderFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::DataProtection::DataProtectionProvider>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::DataProtection::DataProtectionProvider> = L"Windows.Security.Cryptography.DataProtection.DataProtectionProvider";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::DataProtection::IDataProtectionProvider> = L"Windows.Security.Cryptography.DataProtection.IDataProtectionProvider";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::DataProtection::IDataProtectionProviderFactory> = L"Windows.Security.Cryptography.DataProtection.IDataProtectionProviderFactory";
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::DataProtection::IDataProtectionProvider>{ 0x09639948,0xED22,0x4270,{ 0xBD,0x1C,0x6D,0x72,0xC0,0x0F,0x87,0x87 } }; // 09639948-ED22-4270-BD1C-6D72C00F8787
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::DataProtection::IDataProtectionProviderFactory>{ 0xADF33DAC,0x4932,0x4CDF,{ 0xAC,0x41,0x72,0x14,0x33,0x35,0x14,0xCA } }; // ADF33DAC-4932-4CDF-AC41-7214333514CA
    template <> struct default_interface<llm:OS::Security::Cryptography::DataProtection::DataProtectionProvider>{ using type = llm:OS::Security::Cryptography::DataProtection::IDataProtectionProvider; };
    template <> struct abi<llm:OS::Security::Cryptography::DataProtection::IDataProtectionProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ProtectAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall UnprotectAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ProtectStreamAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall UnprotectStreamAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::DataProtection::IDataProtectionProviderFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateOverloadExplicit(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_DataProtection_IDataProtectionProvider
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Storage::Streams::IBuffer>) ProtectAsync(llm:OS::Storage::Streams::IBuffer const& data) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Storage::Streams::IBuffer>) UnprotectAsync(llm:OS::Storage::Streams::IBuffer const& data) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) ProtectStreamAsync(llm:OS::Storage::Streams::IInputStream const& src, llm:OS::Storage::Streams::IOutputStream const& dest) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) UnprotectStreamAsync(llm:OS::Storage::Streams::IInputStream const& src, llm:OS::Storage::Streams::IOutputStream const& dest) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::DataProtection::IDataProtectionProvider>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_DataProtection_IDataProtectionProvider<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_DataProtection_IDataProtectionProviderFactory
    {
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::DataProtection::DataProtectionProvider) CreateOverloadExplicit(param::hstring const& protectionDescriptor) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::DataProtection::IDataProtectionProviderFactory>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_DataProtection_IDataProtectionProviderFactory<D>;
    };
}
#endif
