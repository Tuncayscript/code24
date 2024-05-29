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
#ifndef LLM_OS_ApplicationModel_UserDataAccounts_SystemAccess_0_H
#define LLM_OS_ApplicationModel_UserDataAccounts_SystemAccess_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    struct Uri;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm::OS::Security::Credentials
{
    struct PasswordCredential;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::UserDataAccounts::SystemAccess
{
    enum class DeviceAccountAuthenticationType : int32_t
    {
        Basic = 0,
        OAuth = 1,
        SingleSignOn = 2,
    };
    enum class DeviceAccountIconId : int32_t
    {
        Exchange = 0,
        Msa = 1,
        Outlook = 2,
        Generic = 3,
    };
    enum class DeviceAccountMailAgeFilter : int32_t
    {
        All = 0,
        Last1Day = 1,
        Last3Days = 2,
        Last7Days = 3,
        Last14Days = 4,
        Last30Days = 5,
        Last90Days = 6,
    };
    enum class DeviceAccountServerType : int32_t
    {
        Exchange = 0,
        Pop = 1,
        Imap = 2,
    };
    enum class DeviceAccountSyncScheduleKind : int32_t
    {
        Manual = 0,
        Every15Minutes = 1,
        Every30Minutes = 2,
        Every60Minutes = 3,
        Every2Hours = 4,
        Daily = 5,
        AsItemsArrive = 6,
    };
    struct IDeviceAccountConfiguration;
    struct IDeviceAccountConfiguration2;
    struct IUserDataAccountSystemAccessManagerStatics;
    struct IUserDataAccountSystemAccessManagerStatics2;
    struct DeviceAccountConfiguration;
    struct UserDataAccountSystemAccessManager;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::UserDataAccountSystemAccessManager>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountAuthenticationType>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountIconId>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountMailAgeFilter>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountServerType>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration> = L"Windows.ApplicationModel.UserDataAccounts.SystemAccess.DeviceAccountConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::UserDataAccountSystemAccessManager> = L"Windows.ApplicationModel.UserDataAccounts.SystemAccess.UserDataAccountSystemAccessManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountAuthenticationType> = L"Windows.ApplicationModel.UserDataAccounts.SystemAccess.DeviceAccountAuthenticationType";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountIconId> = L"Windows.ApplicationModel.UserDataAccounts.SystemAccess.DeviceAccountIconId";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountMailAgeFilter> = L"Windows.ApplicationModel.UserDataAccounts.SystemAccess.DeviceAccountMailAgeFilter";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountServerType> = L"Windows.ApplicationModel.UserDataAccounts.SystemAccess.DeviceAccountServerType";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind> = L"Windows.ApplicationModel.UserDataAccounts.SystemAccess.DeviceAccountSyncScheduleKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration> = L"Windows.ApplicationModel.UserDataAccounts.SystemAccess.IDeviceAccountConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2> = L"Windows.ApplicationModel.UserDataAccounts.SystemAccess.IDeviceAccountConfiguration2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics> = L"Windows.ApplicationModel.UserDataAccounts.SystemAccess.IUserDataAccountSystemAccessManagerStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics2> = L"Windows.ApplicationModel.UserDataAccounts.SystemAccess.IUserDataAccountSystemAccessManagerStatics2";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>{ 0xAD0123A3,0xFBDC,0x4D1B,{ 0xBE,0x43,0x5A,0x27,0xEA,0x4A,0x1B,0x63 } }; // AD0123A3-FBDC-4D1B-BE43-5A27EA4A1B63
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>{ 0xF2B2E5A6,0x728D,0x4A4A,{ 0x89,0x45,0x2B,0xF8,0x58,0x01,0x36,0xDE } }; // F2B2E5A6-728D-4A4A-8945-2BF8580136DE
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics>{ 0x9D6B11B9,0xCBE5,0x45F5,{ 0x82,0x2B,0xC2,0x67,0xB8,0x1D,0xBD,0xB6 } }; // 9D6B11B9-CBE5-45F5-822B-C267B81DBDB6
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics2>{ 0x943F854D,0x4B4E,0x439F,{ 0x83,0xD3,0x97,0x9B,0x27,0xC0,0x5A,0xC7 } }; // 943F854D-4B4E-439F-83D3-979B27C05AC7
    template <> struct default_interface<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration>{ using type = llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration; };
    template <> struct abi<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AccountName(void**) noexcept = 0;
            virtual int32_t __stdcall put_AccountName(void*) noexcept = 0;
            virtual int32_t __stdcall get_DeviceAccountTypeId(void**) noexcept = 0;
            virtual int32_t __stdcall put_DeviceAccountTypeId(void*) noexcept = 0;
            virtual int32_t __stdcall get_ServerType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ServerType(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_EmailAddress(void**) noexcept = 0;
            virtual int32_t __stdcall put_EmailAddress(void*) noexcept = 0;
            virtual int32_t __stdcall get_Domain(void**) noexcept = 0;
            virtual int32_t __stdcall put_Domain(void*) noexcept = 0;
            virtual int32_t __stdcall get_EmailSyncEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_EmailSyncEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_ContactsSyncEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_ContactsSyncEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_CalendarSyncEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_CalendarSyncEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_IncomingServerAddress(void**) noexcept = 0;
            virtual int32_t __stdcall put_IncomingServerAddress(void*) noexcept = 0;
            virtual int32_t __stdcall get_IncomingServerPort(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_IncomingServerPort(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_IncomingServerRequiresSsl(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IncomingServerRequiresSsl(bool) noexcept = 0;
            virtual int32_t __stdcall get_IncomingServerUsername(void**) noexcept = 0;
            virtual int32_t __stdcall put_IncomingServerUsername(void*) noexcept = 0;
            virtual int32_t __stdcall get_OutgoingServerAddress(void**) noexcept = 0;
            virtual int32_t __stdcall put_OutgoingServerAddress(void*) noexcept = 0;
            virtual int32_t __stdcall get_OutgoingServerPort(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_OutgoingServerPort(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_OutgoingServerRequiresSsl(bool*) noexcept = 0;
            virtual int32_t __stdcall put_OutgoingServerRequiresSsl(bool) noexcept = 0;
            virtual int32_t __stdcall get_OutgoingServerUsername(void**) noexcept = 0;
            virtual int32_t __stdcall put_OutgoingServerUsername(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IncomingServerCredential(void**) noexcept = 0;
            virtual int32_t __stdcall put_IncomingServerCredential(void*) noexcept = 0;
            virtual int32_t __stdcall get_OutgoingServerCredential(void**) noexcept = 0;
            virtual int32_t __stdcall put_OutgoingServerCredential(void*) noexcept = 0;
            virtual int32_t __stdcall get_OAuthRefreshToken(void**) noexcept = 0;
            virtual int32_t __stdcall put_OAuthRefreshToken(void*) noexcept = 0;
            virtual int32_t __stdcall get_IsExternallyManaged(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsExternallyManaged(bool) noexcept = 0;
            virtual int32_t __stdcall get_AccountIconId(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_AccountIconId(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_AuthenticationType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_AuthenticationType(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_IsSsoAuthenticationSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SsoAccountId(void**) noexcept = 0;
            virtual int32_t __stdcall put_SsoAccountId(void*) noexcept = 0;
            virtual int32_t __stdcall get_AlwaysDownloadFullMessage(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AlwaysDownloadFullMessage(bool) noexcept = 0;
            virtual int32_t __stdcall get_DoesPolicyAllowMailSync(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SyncScheduleKind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SyncScheduleKind(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_MailAgeFilter(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_MailAgeFilter(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_IsClientAuthenticationCertificateRequired(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsClientAuthenticationCertificateRequired(bool) noexcept = 0;
            virtual int32_t __stdcall get_AutoSelectAuthenticationCertificate(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AutoSelectAuthenticationCertificate(bool) noexcept = 0;
            virtual int32_t __stdcall get_AuthenticationCertificateId(void**) noexcept = 0;
            virtual int32_t __stdcall put_AuthenticationCertificateId(void*) noexcept = 0;
            virtual int32_t __stdcall get_CardDavSyncScheduleKind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_CardDavSyncScheduleKind(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_CalDavSyncScheduleKind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_CalDavSyncScheduleKind(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_CardDavServerUrl(void**) noexcept = 0;
            virtual int32_t __stdcall put_CardDavServerUrl(void*) noexcept = 0;
            virtual int32_t __stdcall get_CardDavRequiresSsl(bool*) noexcept = 0;
            virtual int32_t __stdcall put_CardDavRequiresSsl(bool) noexcept = 0;
            virtual int32_t __stdcall get_CalDavServerUrl(void**) noexcept = 0;
            virtual int32_t __stdcall put_CalDavServerUrl(void*) noexcept = 0;
            virtual int32_t __stdcall get_CalDavRequiresSsl(bool*) noexcept = 0;
            virtual int32_t __stdcall put_CalDavRequiresSsl(bool) noexcept = 0;
            virtual int32_t __stdcall get_WasModifiedByUser(bool*) noexcept = 0;
            virtual int32_t __stdcall put_WasModifiedByUser(bool) noexcept = 0;
            virtual int32_t __stdcall get_WasIncomingServerCertificateHashConfirmed(bool*) noexcept = 0;
            virtual int32_t __stdcall put_WasIncomingServerCertificateHashConfirmed(bool) noexcept = 0;
            virtual int32_t __stdcall get_IncomingServerCertificateHash(void**) noexcept = 0;
            virtual int32_t __stdcall put_IncomingServerCertificateHash(void*) noexcept = 0;
            virtual int32_t __stdcall get_IsOutgoingServerAuthenticationRequired(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsOutgoingServerAuthenticationRequired(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsOutgoingServerAuthenticationEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsOutgoingServerAuthenticationEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_WasOutgoingServerCertificateHashConfirmed(bool*) noexcept = 0;
            virtual int32_t __stdcall put_WasOutgoingServerCertificateHashConfirmed(bool) noexcept = 0;
            virtual int32_t __stdcall get_OutgoingServerCertificateHash(void**) noexcept = 0;
            virtual int32_t __stdcall put_OutgoingServerCertificateHash(void*) noexcept = 0;
            virtual int32_t __stdcall get_IsSyncScheduleManagedBySystem(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsSyncScheduleManagedBySystem(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall AddAndShowDeviceAccountsAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SuppressLocalAccountWithAccountAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateDeviceAccountAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DeleteDeviceAccountAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetDeviceAccountConfigurationAsync(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserDataAccounts_SystemAccess_IDeviceAccountConfiguration
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AccountName() const;
        LLM_IMPL_AUTO(void) AccountName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DeviceAccountTypeId() const;
        LLM_IMPL_AUTO(void) DeviceAccountTypeId(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountServerType) ServerType() const;
        LLM_IMPL_AUTO(void) ServerType(llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountServerType const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) EmailAddress() const;
        LLM_IMPL_AUTO(void) EmailAddress(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Domain() const;
        LLM_IMPL_AUTO(void) Domain(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) EmailSyncEnabled() const;
        LLM_IMPL_AUTO(void) EmailSyncEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) ContactsSyncEnabled() const;
        LLM_IMPL_AUTO(void) ContactsSyncEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) CalendarSyncEnabled() const;
        LLM_IMPL_AUTO(void) CalendarSyncEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) IncomingServerAddress() const;
        LLM_IMPL_AUTO(void) IncomingServerAddress(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) IncomingServerPort() const;
        LLM_IMPL_AUTO(void) IncomingServerPort(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IncomingServerRequiresSsl() const;
        LLM_IMPL_AUTO(void) IncomingServerRequiresSsl(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) IncomingServerUsername() const;
        LLM_IMPL_AUTO(void) IncomingServerUsername(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) OutgoingServerAddress() const;
        LLM_IMPL_AUTO(void) OutgoingServerAddress(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) OutgoingServerPort() const;
        LLM_IMPL_AUTO(void) OutgoingServerPort(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) OutgoingServerRequiresSsl() const;
        LLM_IMPL_AUTO(void) OutgoingServerRequiresSsl(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) OutgoingServerUsername() const;
        LLM_IMPL_AUTO(void) OutgoingServerUsername(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserDataAccounts_SystemAccess_IDeviceAccountConfiguration<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserDataAccounts_SystemAccess_IDeviceAccountConfiguration2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Security::Credentials::PasswordCredential) IncomingServerCredential() const;
        LLM_IMPL_AUTO(void) IncomingServerCredential(llm::OS::Security::Credentials::PasswordCredential const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Security::Credentials::PasswordCredential) OutgoingServerCredential() const;
        LLM_IMPL_AUTO(void) OutgoingServerCredential(llm::OS::Security::Credentials::PasswordCredential const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) OAuthRefreshToken() const;
        LLM_IMPL_AUTO(void) OAuthRefreshToken(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsExternallyManaged() const;
        LLM_IMPL_AUTO(void) IsExternallyManaged(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountIconId) AccountIconId() const;
        LLM_IMPL_AUTO(void) AccountIconId(llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountIconId const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountAuthenticationType) AuthenticationType() const;
        LLM_IMPL_AUTO(void) AuthenticationType(llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountAuthenticationType const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSsoAuthenticationSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SsoAccountId() const;
        LLM_IMPL_AUTO(void) SsoAccountId(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AlwaysDownloadFullMessage() const;
        LLM_IMPL_AUTO(void) AlwaysDownloadFullMessage(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) DoesPolicyAllowMailSync() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind) SyncScheduleKind() const;
        LLM_IMPL_AUTO(void) SyncScheduleKind(llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountMailAgeFilter) MailAgeFilter() const;
        LLM_IMPL_AUTO(void) MailAgeFilter(llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountMailAgeFilter const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsClientAuthenticationCertificateRequired() const;
        LLM_IMPL_AUTO(void) IsClientAuthenticationCertificateRequired(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AutoSelectAuthenticationCertificate() const;
        LLM_IMPL_AUTO(void) AutoSelectAuthenticationCertificate(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AuthenticationCertificateId() const;
        LLM_IMPL_AUTO(void) AuthenticationCertificateId(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind) CardDavSyncScheduleKind() const;
        LLM_IMPL_AUTO(void) CardDavSyncScheduleKind(llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind) CalDavSyncScheduleKind() const;
        LLM_IMPL_AUTO(void) CalDavSyncScheduleKind(llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) CardDavServerUrl() const;
        LLM_IMPL_AUTO(void) CardDavServerUrl(llm::OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) CardDavRequiresSsl() const;
        LLM_IMPL_AUTO(void) CardDavRequiresSsl(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) CalDavServerUrl() const;
        LLM_IMPL_AUTO(void) CalDavServerUrl(llm::OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) CalDavRequiresSsl() const;
        LLM_IMPL_AUTO(void) CalDavRequiresSsl(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) WasModifiedByUser() const;
        LLM_IMPL_AUTO(void) WasModifiedByUser(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) WasIncomingServerCertificateHashConfirmed() const;
        LLM_IMPL_AUTO(void) WasIncomingServerCertificateHashConfirmed(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) IncomingServerCertificateHash() const;
        LLM_IMPL_AUTO(void) IncomingServerCertificateHash(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsOutgoingServerAuthenticationRequired() const;
        LLM_IMPL_AUTO(void) IsOutgoingServerAuthenticationRequired(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsOutgoingServerAuthenticationEnabled() const;
        LLM_IMPL_AUTO(void) IsOutgoingServerAuthenticationEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) WasOutgoingServerCertificateHashConfirmed() const;
        LLM_IMPL_AUTO(void) WasOutgoingServerCertificateHashConfirmed(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) OutgoingServerCertificateHash() const;
        LLM_IMPL_AUTO(void) OutgoingServerCertificateHash(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSyncScheduleManagedBySystem() const;
        LLM_IMPL_AUTO(void) IsSyncScheduleManagedBySystem(bool value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserDataAccounts_SystemAccess_IDeviceAccountConfiguration2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserDataAccounts_SystemAccess_IUserDataAccountSystemAccessManagerStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<hstring>>) AddAndShowDeviceAccountsAsync(param::async_iterable<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration> const& accounts) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserDataAccounts_SystemAccess_IUserDataAccountSystemAccessManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserDataAccounts_SystemAccess_IUserDataAccountSystemAccessManagerStatics2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) SuppressLocalAccountWithAccountAsync(param::hstring const& userDataAccountId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) CreateDeviceAccountAsync(llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration const& account) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) DeleteDeviceAccountAsync(param::hstring const& accountId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration>) GetDeviceAccountConfigurationAsync(param::hstring const& accountId) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserDataAccounts_SystemAccess_IUserDataAccountSystemAccessManagerStatics2<D>;
    };
}
#endif
