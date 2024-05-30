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
#ifndef LLM_OS_System_Update_0_H
#define LLM_OS_System_Update_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename T> struct __declspec(empty_bases) EventHandler;
    struct EventRegistrationToken;
    struct HResult;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::System::Update
{
    enum class SystemUpdateAttentionRequiredReason : int32_t
    {
        None = 0,
        NetworkRequired = 1,
        InsufficientDiskSpace = 2,
        InsufficientBattery = 3,
        UpdateBlocked = 4,
    };
    enum class SystemUpdateItemState : int32_t
    {
        NotStarted = 0,
        Initializing = 1,
        Preparing = 2,
        Calculating = 3,
        Downloading = 4,
        Installing = 5,
        Completed = 6,
        RebootRequired = 7,
        Error = 8,
    };
    enum class SystemUpdateManagerState : int32_t
    {
        Idle = 0,
        Detecting = 1,
        ReadyToDownload = 2,
        Downloading = 3,
        ReadyToInstall = 4,
        Installing = 5,
        RebootRequired = 6,
        ReadyToFinalize = 7,
        Finalizing = 8,
        Completed = 9,
        AttentionRequired = 10,
        Error = 11,
    };
    enum class SystemUpdateStartInstallAction : int32_t
    {
        UpToReboot = 0,
        AllowReboot = 1,
    };
    struct ISystemUpdateItem;
    struct ISystemUpdateLastErrorInfo;
    struct ISystemUpdateManagerStatics;
    struct SystemUpdateItem;
    struct SystemUpdateLastErrorInfo;
    struct SystemUpdateManager;
}
namespace llm::impl
{
    template <> struct category<llm:OS::System::Update::ISystemUpdateItem>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Update::ISystemUpdateLastErrorInfo>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Update::ISystemUpdateManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Update::SystemUpdateItem>{ using type = class_category; };
    template <> struct category<llm:OS::System::Update::SystemUpdateLastErrorInfo>{ using type = class_category; };
    template <> struct category<llm:OS::System::Update::SystemUpdateManager>{ using type = class_category; };
    template <> struct category<llm:OS::System::Update::SystemUpdateAttentionRequiredReason>{ using type = enum_category; };
    template <> struct category<llm:OS::System::Update::SystemUpdateItemState>{ using type = enum_category; };
    template <> struct category<llm:OS::System::Update::SystemUpdateManagerState>{ using type = enum_category; };
    template <> struct category<llm:OS::System::Update::SystemUpdateStartInstallAction>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::System::Update::SystemUpdateItem> = L"Windows.System.Update.SystemUpdateItem";
    template <> inline constexpr auto& name_v<llm:OS::System::Update::SystemUpdateLastErrorInfo> = L"Windows.System.Update.SystemUpdateLastErrorInfo";
    template <> inline constexpr auto& name_v<llm:OS::System::Update::SystemUpdateManager> = L"Windows.System.Update.SystemUpdateManager";
    template <> inline constexpr auto& name_v<llm:OS::System::Update::SystemUpdateAttentionRequiredReason> = L"Windows.System.Update.SystemUpdateAttentionRequiredReason";
    template <> inline constexpr auto& name_v<llm:OS::System::Update::SystemUpdateItemState> = L"Windows.System.Update.SystemUpdateItemState";
    template <> inline constexpr auto& name_v<llm:OS::System::Update::SystemUpdateManagerState> = L"Windows.System.Update.SystemUpdateManagerState";
    template <> inline constexpr auto& name_v<llm:OS::System::Update::SystemUpdateStartInstallAction> = L"Windows.System.Update.SystemUpdateStartInstallAction";
    template <> inline constexpr auto& name_v<llm:OS::System::Update::ISystemUpdateItem> = L"Windows.System.Update.ISystemUpdateItem";
    template <> inline constexpr auto& name_v<llm:OS::System::Update::ISystemUpdateLastErrorInfo> = L"Windows.System.Update.ISystemUpdateLastErrorInfo";
    template <> inline constexpr auto& name_v<llm:OS::System::Update::ISystemUpdateManagerStatics> = L"Windows.System.Update.ISystemUpdateManagerStatics";
    template <> inline constexpr guid guid_v<llm:OS::System::Update::ISystemUpdateItem>{ 0x779740EB,0x5624,0x519E,{ 0xA8,0xE2,0x09,0xE9,0x17,0x3B,0x3F,0xB7 } }; // 779740EB-5624-519E-A8E2-09E9173B3FB7
    template <> inline constexpr guid guid_v<llm:OS::System::Update::ISystemUpdateLastErrorInfo>{ 0x7EE887F7,0x8A44,0x5B6E,{ 0xBD,0x07,0x7A,0xEC,0xE4,0x11,0x6E,0xA9 } }; // 7EE887F7-8A44-5B6E-BD07-7AECE4116EA9
    template <> inline constexpr guid guid_v<llm:OS::System::Update::ISystemUpdateManagerStatics>{ 0xB2D3FCEF,0x2971,0x51BE,{ 0xB4,0x1A,0x8B,0xD7,0x03,0xBB,0x70,0x1A } }; // B2D3FCEF-2971-51BE-B41A-8BD703BB701A
    template <> struct default_interface<llm:OS::System::Update::SystemUpdateItem>{ using type = llm:OS::System::Update::ISystemUpdateItem; };
    template <> struct default_interface<llm:OS::System::Update::SystemUpdateLastErrorInfo>{ using type = llm:OS::System::Update::ISystemUpdateLastErrorInfo; };
    template <> struct abi<llm:OS::System::Update::ISystemUpdateItem>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_State(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_Revision(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_DownloadProgress(double*) noexcept = 0;
            virtual int32_t __stdcall get_InstallProgress(double*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Update::ISystemUpdateLastErrorInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_State(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
            virtual int32_t __stdcall get_IsInteractive(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Update::ISystemUpdateManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_State(int32_t*) noexcept = 0;
            virtual int32_t __stdcall add_StateChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_StateChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_DownloadProgress(double*) noexcept = 0;
            virtual int32_t __stdcall get_InstallProgress(double*) noexcept = 0;
            virtual int32_t __stdcall get_UserActiveHoursStart(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_UserActiveHoursEnd(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_UserActiveHoursMax(int32_t*) noexcept = 0;
            virtual int32_t __stdcall TrySetUserActiveHours(int64_t, int64_t, bool*) noexcept = 0;
            virtual int32_t __stdcall get_LastUpdateCheckTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_LastUpdateInstallTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_LastErrorInfo(void**) noexcept = 0;
            virtual int32_t __stdcall GetAutomaticRebootBlockIds(void**) noexcept = 0;
            virtual int32_t __stdcall BlockAutomaticRebootAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall UnblockAutomaticRebootAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
            virtual int32_t __stdcall GetUpdateItems(void**) noexcept = 0;
            virtual int32_t __stdcall get_AttentionRequiredReason(int32_t*) noexcept = 0;
            virtual int32_t __stdcall SetFlightRing(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall GetFlightRing(void**) noexcept = 0;
            virtual int32_t __stdcall StartInstall(int32_t) noexcept = 0;
            virtual int32_t __stdcall RebootToCompleteInstall() noexcept = 0;
            virtual int32_t __stdcall StartCancelUpdates() noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_System_Update_ISystemUpdateItem
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::Update::SystemUpdateItemState) State() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Title() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Revision() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) DownloadProgress() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) InstallProgress() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
    };
    template <> struct consume<llm:OS::System::Update::ISystemUpdateItem>
    {
        template <typename D> using type = consume_Windows_System_Update_ISystemUpdateItem<D>;
    };
    template <typename D>
    struct consume_Windows_System_Update_ISystemUpdateLastErrorInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::Update::SystemUpdateManagerState) State() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsInteractive() const;
    };
    template <> struct consume<llm:OS::System::Update::ISystemUpdateLastErrorInfo>
    {
        template <typename D> using type = consume_Windows_System_Update_ISystemUpdateLastErrorInfo<D>;
    };
    template <typename D>
    struct consume_Windows_System_Update_ISystemUpdateManagerStatics
    {
        LLM_IMPL_AUTO(bool) IsSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::Update::SystemUpdateManagerState) State() const;
        LLM_IMPL_AUTO(llm::event_token) StateChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        using StateChanged_revoker = impl::event_revoker<llm:OS::System::Update::ISystemUpdateManagerStatics, &impl::abi_t<llm:OS::System::Update::ISystemUpdateManagerStatics>::remove_StateChanged>;
        [[nodiscard]] StateChanged_revoker StateChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) StateChanged(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(double) DownloadProgress() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) InstallProgress() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) UserActiveHoursStart() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) UserActiveHoursEnd() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) UserActiveHoursMax() const;
        LLM_IMPL_AUTO(bool) TrySetUserActiveHours(llm:OS::Foundation::TimeSpan const& start, llm:OS::Foundation::TimeSpan const& end) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::DateTime) LastUpdateCheckTime() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::DateTime) LastUpdateInstallTime() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::Update::SystemUpdateLastErrorInfo) LastErrorInfo() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<hstring>) GetAutomaticRebootBlockIds() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) BlockAutomaticRebootAsync(param::hstring const& lockId) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) UnblockAutomaticRebootAsync(param::hstring const& lockId) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::System::Update::SystemUpdateItem>) GetUpdateItems() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::Update::SystemUpdateAttentionRequiredReason) AttentionRequiredReason() const;
        LLM_IMPL_AUTO(bool) SetFlightRing(param::hstring const& flightRing) const;
        LLM_IMPL_AUTO(hstring) GetFlightRing() const;
        LLM_IMPL_AUTO(void) StartInstall(llm:OS::System::Update::SystemUpdateStartInstallAction const& action) const;
        LLM_IMPL_AUTO(void) RebootToCompleteInstall() const;
        LLM_IMPL_AUTO(void) StartCancelUpdates() const;
    };
    template <> struct consume<llm:OS::System::Update::ISystemUpdateManagerStatics>
    {
        template <typename D> using type = consume_Windows_System_Update_ISystemUpdateManagerStatics<D>;
    };
}
#endif
