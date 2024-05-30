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
#ifndef LLM_OS_Security_ExchangeActiveSyncProvisioning_0_H
#define LLM_OS_Security_ExchangeActiveSyncProvisioning_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm:OS::Security::ExchangeActiveSyncProvisioning
{
    enum class EasDisallowConvenienceLogonResult : int32_t
    {
        NotEvaluated = 0,
        Compliant = 1,
        CanBeCompliant = 2,
        RequestedPolicyIsStricter = 3,
    };
    enum class EasEncryptionProviderType : int32_t
    {
        NotEvaluated = 0,
        WindowsEncryption = 1,
        OtherEncryption = 2,
    };
    enum class EasMaxInactivityTimeLockResult : int32_t
    {
        NotEvaluated = 0,
        Compliant = 1,
        CanBeCompliant = 2,
        RequestedPolicyIsStricter = 3,
        InvalidParameter = 4,
    };
    enum class EasMaxPasswordFailedAttemptsResult : int32_t
    {
        NotEvaluated = 0,
        Compliant = 1,
        CanBeCompliant = 2,
        RequestedPolicyIsStricter = 3,
        InvalidParameter = 4,
    };
    enum class EasMinPasswordComplexCharactersResult : int32_t
    {
        NotEvaluated = 0,
        Compliant = 1,
        CanBeCompliant = 2,
        RequestedPolicyIsStricter = 3,
        RequestedPolicyNotEnforceable = 4,
        InvalidParameter = 5,
        CurrentUserHasBlankPassword = 6,
        AdminsHaveBlankPassword = 7,
        UserCannotChangePassword = 8,
        AdminsCannotChangePassword = 9,
        LocalControlledUsersCannotChangePassword = 10,
        ConnectedAdminsProviderPolicyIsWeak = 11,
        ConnectedUserProviderPolicyIsWeak = 12,
        ChangeConnectedAdminsPassword = 13,
        ChangeConnectedUserPassword = 14,
    };
    enum class EasMinPasswordLengthResult : int32_t
    {
        NotEvaluated = 0,
        Compliant = 1,
        CanBeCompliant = 2,
        RequestedPolicyIsStricter = 3,
        RequestedPolicyNotEnforceable = 4,
        InvalidParameter = 5,
        CurrentUserHasBlankPassword = 6,
        AdminsHaveBlankPassword = 7,
        UserCannotChangePassword = 8,
        AdminsCannotChangePassword = 9,
        LocalControlledUsersCannotChangePassword = 10,
        ConnectedAdminsProviderPolicyIsWeak = 11,
        ConnectedUserProviderPolicyIsWeak = 12,
        ChangeConnectedAdminsPassword = 13,
        ChangeConnectedUserPassword = 14,
    };
    enum class EasPasswordExpirationResult : int32_t
    {
        NotEvaluated = 0,
        Compliant = 1,
        CanBeCompliant = 2,
        RequestedPolicyIsStricter = 3,
        RequestedExpirationIncompatible = 4,
        InvalidParameter = 5,
        UserCannotChangePassword = 6,
        AdminsCannotChangePassword = 7,
        LocalControlledUsersCannotChangePassword = 8,
    };
    enum class EasPasswordHistoryResult : int32_t
    {
        NotEvaluated = 0,
        Compliant = 1,
        CanBeCompliant = 2,
        RequestedPolicyIsStricter = 3,
        InvalidParameter = 4,
    };
    enum class EasRequireEncryptionResult : int32_t
    {
        NotEvaluated = 0,
        Compliant = 1,
        CanBeCompliant = 2,
        NotProvisionedOnAllVolumes = 3,
        DeFixedDataNotSupported = 4,
        FixedDataNotSupported = 4,
        DeHardwareNotCompliant = 5,
        HardwareNotCompliant = 5,
        DeWinReNotConfigured = 6,
        LockNotConfigured = 6,
        DeProtectionSuspended = 7,
        ProtectionSuspended = 7,
        DeOsVolumeNotProtected = 8,
        OsVolumeNotProtected = 8,
        DeProtectionNotYetEnabled = 9,
        ProtectionNotYetEnabled = 9,
        NoFeatureLicense = 10,
        OsNotProtected = 11,
        UnexpectedFailure = 12,
    };
    struct IEasClientDeviceInformation;
    struct IEasClientDeviceInformation2;
    struct IEasClientSecurityPolicy;
    struct IEasComplianceResults;
    struct IEasComplianceResults2;
    struct EasClientDeviceInformation;
    struct EasClientSecurityPolicy;
    struct EasComplianceResults;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::ExchangeActiveSyncProvisioning::EasClientDeviceInformation>{ using type = class_category; };
    template <> struct category<llm:OS::Security::ExchangeActiveSyncProvisioning::EasClientSecurityPolicy>{ using type = class_category; };
    template <> struct category<llm:OS::Security::ExchangeActiveSyncProvisioning::EasComplianceResults>{ using type = class_category; };
    template <> struct category<llm:OS::Security::ExchangeActiveSyncProvisioning::EasDisallowConvenienceLogonResult>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::ExchangeActiveSyncProvisioning::EasEncryptionProviderType>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::ExchangeActiveSyncProvisioning::EasMaxInactivityTimeLockResult>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::ExchangeActiveSyncProvisioning::EasMaxPasswordFailedAttemptsResult>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::ExchangeActiveSyncProvisioning::EasMinPasswordComplexCharactersResult>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::ExchangeActiveSyncProvisioning::EasMinPasswordLengthResult>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::ExchangeActiveSyncProvisioning::EasPasswordExpirationResult>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::ExchangeActiveSyncProvisioning::EasPasswordHistoryResult>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::ExchangeActiveSyncProvisioning::EasRequireEncryptionResult>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Security::ExchangeActiveSyncProvisioning::EasClientDeviceInformation> = L"Windows.Security.ExchangeActiveSyncProvisioning.EasClientDeviceInformation";
    template <> inline constexpr auto& name_v<llm:OS::Security::ExchangeActiveSyncProvisioning::EasClientSecurityPolicy> = L"Windows.Security.ExchangeActiveSyncProvisioning.EasClientSecurityPolicy";
    template <> inline constexpr auto& name_v<llm:OS::Security::ExchangeActiveSyncProvisioning::EasComplianceResults> = L"Windows.Security.ExchangeActiveSyncProvisioning.EasComplianceResults";
    template <> inline constexpr auto& name_v<llm:OS::Security::ExchangeActiveSyncProvisioning::EasDisallowConvenienceLogonResult> = L"Windows.Security.ExchangeActiveSyncProvisioning.EasDisallowConvenienceLogonResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::ExchangeActiveSyncProvisioning::EasEncryptionProviderType> = L"Windows.Security.ExchangeActiveSyncProvisioning.EasEncryptionProviderType";
    template <> inline constexpr auto& name_v<llm:OS::Security::ExchangeActiveSyncProvisioning::EasMaxInactivityTimeLockResult> = L"Windows.Security.ExchangeActiveSyncProvisioning.EasMaxInactivityTimeLockResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::ExchangeActiveSyncProvisioning::EasMaxPasswordFailedAttemptsResult> = L"Windows.Security.ExchangeActiveSyncProvisioning.EasMaxPasswordFailedAttemptsResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::ExchangeActiveSyncProvisioning::EasMinPasswordComplexCharactersResult> = L"Windows.Security.ExchangeActiveSyncProvisioning.EasMinPasswordComplexCharactersResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::ExchangeActiveSyncProvisioning::EasMinPasswordLengthResult> = L"Windows.Security.ExchangeActiveSyncProvisioning.EasMinPasswordLengthResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::ExchangeActiveSyncProvisioning::EasPasswordExpirationResult> = L"Windows.Security.ExchangeActiveSyncProvisioning.EasPasswordExpirationResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::ExchangeActiveSyncProvisioning::EasPasswordHistoryResult> = L"Windows.Security.ExchangeActiveSyncProvisioning.EasPasswordHistoryResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::ExchangeActiveSyncProvisioning::EasRequireEncryptionResult> = L"Windows.Security.ExchangeActiveSyncProvisioning.EasRequireEncryptionResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation> = L"Windows.Security.ExchangeActiveSyncProvisioning.IEasClientDeviceInformation";
    template <> inline constexpr auto& name_v<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2> = L"Windows.Security.ExchangeActiveSyncProvisioning.IEasClientDeviceInformation2";
    template <> inline constexpr auto& name_v<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy> = L"Windows.Security.ExchangeActiveSyncProvisioning.IEasClientSecurityPolicy";
    template <> inline constexpr auto& name_v<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults> = L"Windows.Security.ExchangeActiveSyncProvisioning.IEasComplianceResults";
    template <> inline constexpr auto& name_v<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2> = L"Windows.Security.ExchangeActiveSyncProvisioning.IEasComplianceResults2";
    template <> inline constexpr guid guid_v<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>{ 0x54DFD981,0x1968,0x4CA3,{ 0xB9,0x58,0xE5,0x95,0xD1,0x65,0x05,0xEB } }; // 54DFD981-1968-4CA3-B958-E595D16505EB
    template <> inline constexpr guid guid_v<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2>{ 0xFFB35923,0xBB26,0x4D6A,{ 0x81,0xBC,0x16,0x5A,0xEE,0x0A,0xD7,0x54 } }; // FFB35923-BB26-4D6A-81BC-165AEE0AD754
    template <> inline constexpr guid guid_v<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>{ 0x45B72362,0xDFBA,0x4A9B,{ 0xAC,0xED,0x6F,0xE2,0xAD,0xCB,0x64,0x20 } }; // 45B72362-DFBA-4A9B-ACED-6FE2ADCB6420
    template <> inline constexpr guid guid_v<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>{ 0x463C299C,0x7F19,0x4C66,{ 0xB4,0x03,0xCB,0x45,0xDD,0x57,0xA2,0xB3 } }; // 463C299C-7F19-4C66-B403-CB45DD57A2B3
    template <> inline constexpr guid guid_v<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2>{ 0x2FBE60C9,0x1AA8,0x47F5,{ 0x88,0xBB,0xCB,0x3E,0xF0,0xBF,0xFB,0x15 } }; // 2FBE60C9-1AA8-47F5-88BB-CB3EF0BFFB15
    template <> struct default_interface<llm:OS::Security::ExchangeActiveSyncProvisioning::EasClientDeviceInformation>{ using type = llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation; };
    template <> struct default_interface<llm:OS::Security::ExchangeActiveSyncProvisioning::EasClientSecurityPolicy>{ using type = llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy; };
    template <> struct default_interface<llm:OS::Security::ExchangeActiveSyncProvisioning::EasComplianceResults>{ using type = llm:OS::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults; };
    template <> struct abi<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall get_OperatingSystem(void**) noexcept = 0;
            virtual int32_t __stdcall get_FriendlyName(void**) noexcept = 0;
            virtual int32_t __stdcall get_SystemManufacturer(void**) noexcept = 0;
            virtual int32_t __stdcall get_SystemProductName(void**) noexcept = 0;
            virtual int32_t __stdcall get_SystemSku(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SystemHardwareVersion(void**) noexcept = 0;
            virtual int32_t __stdcall get_SystemFirmwareVersion(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_RequireEncryption(bool*) noexcept = 0;
            virtual int32_t __stdcall put_RequireEncryption(bool) noexcept = 0;
            virtual int32_t __stdcall get_MinPasswordLength(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall put_MinPasswordLength(uint8_t) noexcept = 0;
            virtual int32_t __stdcall get_DisallowConvenienceLogon(bool*) noexcept = 0;
            virtual int32_t __stdcall put_DisallowConvenienceLogon(bool) noexcept = 0;
            virtual int32_t __stdcall get_MinPasswordComplexCharacters(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall put_MinPasswordComplexCharacters(uint8_t) noexcept = 0;
            virtual int32_t __stdcall get_PasswordExpiration(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_PasswordExpiration(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_PasswordHistory(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_PasswordHistory(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_MaxPasswordFailedAttempts(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall put_MaxPasswordFailedAttempts(uint8_t) noexcept = 0;
            virtual int32_t __stdcall get_MaxInactivityTimeLock(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_MaxInactivityTimeLock(int64_t) noexcept = 0;
            virtual int32_t __stdcall CheckCompliance(void**) noexcept = 0;
            virtual int32_t __stdcall ApplyAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Compliant(bool*) noexcept = 0;
            virtual int32_t __stdcall get_RequireEncryptionResult(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MinPasswordLengthResult(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_DisallowConvenienceLogonResult(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MinPasswordComplexCharactersResult(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PasswordExpirationResult(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PasswordHistoryResult(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MaxPasswordFailedAttemptsResult(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MaxInactivityTimeLockResult(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_EncryptionProviderType(int32_t*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientDeviceInformation
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) OperatingSystem() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) FriendlyName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SystemManufacturer() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SystemProductName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SystemSku() const;
    };
    template <> struct consume<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>
    {
        template <typename D> using type = consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientDeviceInformation<D>;
    };
    template <typename D>
    struct consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientDeviceInformation2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SystemHardwareVersion() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SystemFirmwareVersion() const;
    };
    template <> struct consume<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2>
    {
        template <typename D> using type = consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientDeviceInformation2<D>;
    };
    template <typename D>
    struct consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) RequireEncryption() const;
        LLM_IMPL_AUTO(void) RequireEncryption(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint8_t) MinPasswordLength() const;
        LLM_IMPL_AUTO(void) MinPasswordLength(uint8_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) DisallowConvenienceLogon() const;
        LLM_IMPL_AUTO(void) DisallowConvenienceLogon(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint8_t) MinPasswordComplexCharacters() const;
        LLM_IMPL_AUTO(void) MinPasswordComplexCharacters(uint8_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) PasswordExpiration() const;
        LLM_IMPL_AUTO(void) PasswordExpiration(llm:OS::Foundation::TimeSpan const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) PasswordHistory() const;
        LLM_IMPL_AUTO(void) PasswordHistory(uint32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint8_t) MaxPasswordFailedAttempts() const;
        LLM_IMPL_AUTO(void) MaxPasswordFailedAttempts(uint8_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) MaxInactivityTimeLock() const;
        LLM_IMPL_AUTO(void) MaxInactivityTimeLock(llm:OS::Foundation::TimeSpan const& value) const;
        LLM_IMPL_AUTO(llm:OS::Security::ExchangeActiveSyncProvisioning::EasComplianceResults) CheckCompliance() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::ExchangeActiveSyncProvisioning::EasComplianceResults>) ApplyAsync() const;
    };
    template <> struct consume<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>
    {
        template <typename D> using type = consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasClientSecurityPolicy<D>;
    };
    template <typename D>
    struct consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasComplianceResults
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Compliant() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::ExchangeActiveSyncProvisioning::EasRequireEncryptionResult) RequireEncryptionResult() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::ExchangeActiveSyncProvisioning::EasMinPasswordLengthResult) MinPasswordLengthResult() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::ExchangeActiveSyncProvisioning::EasDisallowConvenienceLogonResult) DisallowConvenienceLogonResult() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::ExchangeActiveSyncProvisioning::EasMinPasswordComplexCharactersResult) MinPasswordComplexCharactersResult() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::ExchangeActiveSyncProvisioning::EasPasswordExpirationResult) PasswordExpirationResult() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::ExchangeActiveSyncProvisioning::EasPasswordHistoryResult) PasswordHistoryResult() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::ExchangeActiveSyncProvisioning::EasMaxPasswordFailedAttemptsResult) MaxPasswordFailedAttemptsResult() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::ExchangeActiveSyncProvisioning::EasMaxInactivityTimeLockResult) MaxInactivityTimeLockResult() const;
    };
    template <> struct consume<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>
    {
        template <typename D> using type = consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasComplianceResults<D>;
    };
    template <typename D>
    struct consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasComplianceResults2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::ExchangeActiveSyncProvisioning::EasEncryptionProviderType) EncryptionProviderType() const;
    };
    template <> struct consume<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2>
    {
        template <typename D> using type = consume_Windows_Security_ExchangeActiveSyncProvisioning_IEasComplianceResults2<D>;
    };
}
#endif
