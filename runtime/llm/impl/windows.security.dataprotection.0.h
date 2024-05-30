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
#ifndef LLM_OS_Security_DataProtection_0_H
#define LLM_OS_Security_DataProtection_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct Deferral;
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Storage
{
    struct IStorageItem;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IBuffer;
}
LLM_EXPORT namespace llm:OS::System
{
    struct User;
}
LLM_EXPORT namespace llm:OS::Security::DataProtection
{
    enum class UserDataAvailability : int32_t
    {
        Always = 0,
        AfterFirstUnlock = 1,
        WhileUnlocked = 2,
    };
    enum class UserDataBufferUnprotectStatus : int32_t
    {
        Succeeded = 0,
        Unavailable = 1,
    };
    enum class UserDataStorageItemProtectionStatus : int32_t
    {
        Succeeded = 0,
        NotProtectable = 1,
        DataUnavailable = 2,
    };
    struct IUserDataAvailabilityStateChangedEventArgs;
    struct IUserDataBufferUnprotectResult;
    struct IUserDataProtectionManager;
    struct IUserDataProtectionManagerStatics;
    struct IUserDataStorageItemProtectionInfo;
    struct UserDataAvailabilityStateChangedEventArgs;
    struct UserDataBufferUnprotectResult;
    struct UserDataProtectionManager;
    struct UserDataStorageItemProtectionInfo;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Security::DataProtection::IUserDataAvailabilityStateChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::DataProtection::IUserDataBufferUnprotectResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::DataProtection::IUserDataProtectionManager>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::DataProtection::IUserDataProtectionManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::DataProtection::IUserDataStorageItemProtectionInfo>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::DataProtection::UserDataAvailabilityStateChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Security::DataProtection::UserDataBufferUnprotectResult>{ using type = class_category; };
    template <> struct category<llm:OS::Security::DataProtection::UserDataProtectionManager>{ using type = class_category; };
    template <> struct category<llm:OS::Security::DataProtection::UserDataStorageItemProtectionInfo>{ using type = class_category; };
    template <> struct category<llm:OS::Security::DataProtection::UserDataAvailability>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::DataProtection::UserDataBufferUnprotectStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::DataProtection::UserDataStorageItemProtectionStatus>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Security::DataProtection::UserDataAvailabilityStateChangedEventArgs> = L"Windows.Security.DataProtection.UserDataAvailabilityStateChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Security::DataProtection::UserDataBufferUnprotectResult> = L"Windows.Security.DataProtection.UserDataBufferUnprotectResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::DataProtection::UserDataProtectionManager> = L"Windows.Security.DataProtection.UserDataProtectionManager";
    template <> inline constexpr auto& name_v<llm:OS::Security::DataProtection::UserDataStorageItemProtectionInfo> = L"Windows.Security.DataProtection.UserDataStorageItemProtectionInfo";
    template <> inline constexpr auto& name_v<llm:OS::Security::DataProtection::UserDataAvailability> = L"Windows.Security.DataProtection.UserDataAvailability";
    template <> inline constexpr auto& name_v<llm:OS::Security::DataProtection::UserDataBufferUnprotectStatus> = L"Windows.Security.DataProtection.UserDataBufferUnprotectStatus";
    template <> inline constexpr auto& name_v<llm:OS::Security::DataProtection::UserDataStorageItemProtectionStatus> = L"Windows.Security.DataProtection.UserDataStorageItemProtectionStatus";
    template <> inline constexpr auto& name_v<llm:OS::Security::DataProtection::IUserDataAvailabilityStateChangedEventArgs> = L"Windows.Security.DataProtection.IUserDataAvailabilityStateChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Security::DataProtection::IUserDataBufferUnprotectResult> = L"Windows.Security.DataProtection.IUserDataBufferUnprotectResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::DataProtection::IUserDataProtectionManager> = L"Windows.Security.DataProtection.IUserDataProtectionManager";
    template <> inline constexpr auto& name_v<llm:OS::Security::DataProtection::IUserDataProtectionManagerStatics> = L"Windows.Security.DataProtection.IUserDataProtectionManagerStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::DataProtection::IUserDataStorageItemProtectionInfo> = L"Windows.Security.DataProtection.IUserDataStorageItemProtectionInfo";
    template <> inline constexpr guid guid_v<llm:OS::Security::DataProtection::IUserDataAvailabilityStateChangedEventArgs>{ 0xA76582C9,0x06A2,0x4273,{ 0xA8,0x03,0x83,0x4C,0x9F,0x87,0xFB,0xEB } }; // A76582C9-06A2-4273-A803-834C9F87FBEB
    template <> inline constexpr guid guid_v<llm:OS::Security::DataProtection::IUserDataBufferUnprotectResult>{ 0x8EFD0E90,0xFA9A,0x46A4,{ 0xA3,0x77,0x01,0xCE,0xBF,0x1E,0x74,0xD8 } }; // 8EFD0E90-FA9A-46A4-A377-01CEBF1E74D8
    template <> inline constexpr guid guid_v<llm:OS::Security::DataProtection::IUserDataProtectionManager>{ 0x1F13237D,0xB42E,0x4A88,{ 0x94,0x80,0x0F,0x24,0x09,0x24,0xC8,0x76 } }; // 1F13237D-B42E-4A88-9480-0F240924C876
    template <> inline constexpr guid guid_v<llm:OS::Security::DataProtection::IUserDataProtectionManagerStatics>{ 0x977780E8,0x6DCE,0x4FAE,{ 0xAF,0x85,0x78,0x2A,0xC2,0xCF,0x45,0x72 } }; // 977780E8-6DCE-4FAE-AF85-782AC2CF4572
    template <> inline constexpr guid guid_v<llm:OS::Security::DataProtection::IUserDataStorageItemProtectionInfo>{ 0x5B6680F6,0xE87F,0x40A1,{ 0xB1,0x9D,0xA6,0x18,0x7A,0x0C,0x66,0x2F } }; // 5B6680F6-E87F-40A1-B19D-A6187A0C662F
    template <> struct default_interface<llm:OS::Security::DataProtection::UserDataAvailabilityStateChangedEventArgs>{ using type = llm:OS::Security::DataProtection::IUserDataAvailabilityStateChangedEventArgs; };
    template <> struct default_interface<llm:OS::Security::DataProtection::UserDataBufferUnprotectResult>{ using type = llm:OS::Security::DataProtection::IUserDataBufferUnprotectResult; };
    template <> struct default_interface<llm:OS::Security::DataProtection::UserDataProtectionManager>{ using type = llm:OS::Security::DataProtection::IUserDataProtectionManager; };
    template <> struct default_interface<llm:OS::Security::DataProtection::UserDataStorageItemProtectionInfo>{ using type = llm:OS::Security::DataProtection::IUserDataStorageItemProtectionInfo; };
    template <> struct abi<llm:OS::Security::DataProtection::IUserDataAvailabilityStateChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::DataProtection::IUserDataBufferUnprotectResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_UnprotectedBuffer(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::DataProtection::IUserDataProtectionManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ProtectStorageItemAsync(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetStorageItemProtectionInfoAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ProtectBufferAsync(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall UnprotectBufferAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall IsContinuedDataAvailabilityExpected(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall add_DataAvailabilityStateChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_DataAvailabilityStateChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::DataProtection::IUserDataProtectionManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryGetDefault(void**) noexcept = 0;
            virtual int32_t __stdcall TryGetForUser(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::DataProtection::IUserDataStorageItemProtectionInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Availability(int32_t*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Security_DataProtection_IUserDataAvailabilityStateChangedEventArgs
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm:OS::Security::DataProtection::IUserDataAvailabilityStateChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_Security_DataProtection_IUserDataAvailabilityStateChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Security_DataProtection_IUserDataBufferUnprotectResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::DataProtection::UserDataBufferUnprotectStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) UnprotectedBuffer() const;
    };
    template <> struct consume<llm:OS::Security::DataProtection::IUserDataBufferUnprotectResult>
    {
        template <typename D> using type = consume_Windows_Security_DataProtection_IUserDataBufferUnprotectResult<D>;
    };
    template <typename D>
    struct consume_Windows_Security_DataProtection_IUserDataProtectionManager
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::DataProtection::UserDataStorageItemProtectionStatus>) ProtectStorageItemAsync(llm:OS::Storage::IStorageItem const& storageItem, llm:OS::Security::DataProtection::UserDataAvailability const& availability) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::DataProtection::UserDataStorageItemProtectionInfo>) GetStorageItemProtectionInfoAsync(llm:OS::Storage::IStorageItem const& storageItem) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Storage::Streams::IBuffer>) ProtectBufferAsync(llm:OS::Storage::Streams::IBuffer const& unprotectedBuffer, llm:OS::Security::DataProtection::UserDataAvailability const& availability) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::DataProtection::UserDataBufferUnprotectResult>) UnprotectBufferAsync(llm:OS::Storage::Streams::IBuffer const& protectedBuffer) const;
        LLM_IMPL_AUTO(bool) IsContinuedDataAvailabilityExpected(llm:OS::Security::DataProtection::UserDataAvailability const& availability) const;
        LLM_IMPL_AUTO(llm::event_token) DataAvailabilityStateChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Security::DataProtection::UserDataProtectionManager, llm:OS::Security::DataProtection::UserDataAvailabilityStateChangedEventArgs> const& handler) const;
        using DataAvailabilityStateChanged_revoker = impl::event_revoker<llm:OS::Security::DataProtection::IUserDataProtectionManager, &impl::abi_t<llm:OS::Security::DataProtection::IUserDataProtectionManager>::remove_DataAvailabilityStateChanged>;
        [[nodiscard]] DataAvailabilityStateChanged_revoker DataAvailabilityStateChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Security::DataProtection::UserDataProtectionManager, llm:OS::Security::DataProtection::UserDataAvailabilityStateChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) DataAvailabilityStateChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Security::DataProtection::IUserDataProtectionManager>
    {
        template <typename D> using type = consume_Windows_Security_DataProtection_IUserDataProtectionManager<D>;
    };
    template <typename D>
    struct consume_Windows_Security_DataProtection_IUserDataProtectionManagerStatics
    {
        LLM_IMPL_AUTO(llm:OS::Security::DataProtection::UserDataProtectionManager) TryGetDefault() const;
        LLM_IMPL_AUTO(llm:OS::Security::DataProtection::UserDataProtectionManager) TryGetForUser(llm:OS::System::User const& user) const;
    };
    template <> struct consume<llm:OS::Security::DataProtection::IUserDataProtectionManagerStatics>
    {
        template <typename D> using type = consume_Windows_Security_DataProtection_IUserDataProtectionManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_DataProtection_IUserDataStorageItemProtectionInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::DataProtection::UserDataAvailability) Availability() const;
    };
    template <> struct consume<llm:OS::Security::DataProtection::IUserDataStorageItemProtectionInfo>
    {
        template <typename D> using type = consume_Windows_Security_DataProtection_IUserDataStorageItemProtectionInfo<D>;
    };
}
#endif
