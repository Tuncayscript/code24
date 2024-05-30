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
#ifndef LLM_OS_Media_AppBroadcasting_0_H
#define LLM_OS_Media_AppBroadcasting_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::System
{
    struct User;
}
LLM_EXPORT namespace llm:OS::Media::AppBroadcasting
{
    struct IAppBroadcastingMonitor;
    struct IAppBroadcastingStatus;
    struct IAppBroadcastingStatusDetails;
    struct IAppBroadcastingUI;
    struct IAppBroadcastingUIStatics;
    struct AppBroadcastingMonitor;
    struct AppBroadcastingStatus;
    struct AppBroadcastingStatusDetails;
    struct AppBroadcastingUI;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::AppBroadcasting::IAppBroadcastingMonitor>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::AppBroadcasting::IAppBroadcastingStatus>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::AppBroadcasting::IAppBroadcastingUI>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::AppBroadcasting::IAppBroadcastingUIStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::AppBroadcasting::AppBroadcastingMonitor>{ using type = class_category; };
    template <> struct category<llm:OS::Media::AppBroadcasting::AppBroadcastingStatus>{ using type = class_category; };
    template <> struct category<llm:OS::Media::AppBroadcasting::AppBroadcastingStatusDetails>{ using type = class_category; };
    template <> struct category<llm:OS::Media::AppBroadcasting::AppBroadcastingUI>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::AppBroadcasting::AppBroadcastingMonitor> = L"Windows.Media.AppBroadcasting.AppBroadcastingMonitor";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppBroadcasting::AppBroadcastingStatus> = L"Windows.Media.AppBroadcasting.AppBroadcastingStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppBroadcasting::AppBroadcastingStatusDetails> = L"Windows.Media.AppBroadcasting.AppBroadcastingStatusDetails";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppBroadcasting::AppBroadcastingUI> = L"Windows.Media.AppBroadcasting.AppBroadcastingUI";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppBroadcasting::IAppBroadcastingMonitor> = L"Windows.Media.AppBroadcasting.IAppBroadcastingMonitor";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppBroadcasting::IAppBroadcastingStatus> = L"Windows.Media.AppBroadcasting.IAppBroadcastingStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails> = L"Windows.Media.AppBroadcasting.IAppBroadcastingStatusDetails";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppBroadcasting::IAppBroadcastingUI> = L"Windows.Media.AppBroadcasting.IAppBroadcastingUI";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppBroadcasting::IAppBroadcastingUIStatics> = L"Windows.Media.AppBroadcasting.IAppBroadcastingUIStatics";
    template <> inline constexpr guid guid_v<llm:OS::Media::AppBroadcasting::IAppBroadcastingMonitor>{ 0x00F95A68,0x8907,0x48A0,{ 0xB8,0xEF,0x24,0xD2,0x08,0x13,0x75,0x42 } }; // 00F95A68-8907-48A0-B8EF-24D208137542
    template <> inline constexpr guid guid_v<llm:OS::Media::AppBroadcasting::IAppBroadcastingStatus>{ 0x1225E4DF,0x03A1,0x42F8,{ 0x8B,0x80,0xC9,0x22,0x8C,0xD9,0xCF,0x2E } }; // 1225E4DF-03A1-42F8-8B80-C9228CD9CF2E
    template <> inline constexpr guid guid_v<llm:OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails>{ 0x069DADA4,0xB573,0x4E3C,{ 0x8E,0x19,0x1B,0xAF,0xAC,0xD0,0x97,0x13 } }; // 069DADA4-B573-4E3C-8E19-1BAFACD09713
    template <> inline constexpr guid guid_v<llm:OS::Media::AppBroadcasting::IAppBroadcastingUI>{ 0xE56F9F8F,0xEE99,0x4DCA,{ 0xA3,0xC3,0x70,0xAF,0x3D,0xB4,0x4F,0x5F } }; // E56F9F8F-EE99-4DCA-A3C3-70AF3DB44F5F
    template <> inline constexpr guid guid_v<llm:OS::Media::AppBroadcasting::IAppBroadcastingUIStatics>{ 0x55A8A79D,0x23CB,0x4579,{ 0x9C,0x34,0x88,0x6F,0xE0,0x2C,0x04,0x5A } }; // 55A8A79D-23CB-4579-9C34-886FE02C045A
    template <> struct default_interface<llm:OS::Media::AppBroadcasting::AppBroadcastingMonitor>{ using type = llm:OS::Media::AppBroadcasting::IAppBroadcastingMonitor; };
    template <> struct default_interface<llm:OS::Media::AppBroadcasting::AppBroadcastingStatus>{ using type = llm:OS::Media::AppBroadcasting::IAppBroadcastingStatus; };
    template <> struct default_interface<llm:OS::Media::AppBroadcasting::AppBroadcastingStatusDetails>{ using type = llm:OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails; };
    template <> struct default_interface<llm:OS::Media::AppBroadcasting::AppBroadcastingUI>{ using type = llm:OS::Media::AppBroadcasting::IAppBroadcastingUI; };
    template <> struct abi<llm:OS::Media::AppBroadcasting::IAppBroadcastingMonitor>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsCurrentAppBroadcasting(bool*) noexcept = 0;
            virtual int32_t __stdcall add_IsCurrentAppBroadcastingChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_IsCurrentAppBroadcastingChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::AppBroadcasting::IAppBroadcastingStatus>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CanStartBroadcast(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Details(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsAnyAppBroadcasting(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsCaptureResourceUnavailable(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsGameStreamInProgress(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsGpuConstrained(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsAppInactive(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsBlockedForApp(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsDisabledByUser(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsDisabledBySystem(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::AppBroadcasting::IAppBroadcastingUI>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetStatus(void**) noexcept = 0;
            virtual int32_t __stdcall ShowBroadcastUI() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::AppBroadcasting::IAppBroadcastingUIStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
            virtual int32_t __stdcall GetForUser(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_AppBroadcasting_IAppBroadcastingMonitor
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsCurrentAppBroadcasting() const;
        LLM_IMPL_AUTO(llm::event_token) IsCurrentAppBroadcastingChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::AppBroadcasting::AppBroadcastingMonitor, llm:OS::Foundation::IInspectable> const& handler) const;
        using IsCurrentAppBroadcastingChanged_revoker = impl::event_revoker<llm:OS::Media::AppBroadcasting::IAppBroadcastingMonitor, &impl::abi_t<llm:OS::Media::AppBroadcasting::IAppBroadcastingMonitor>::remove_IsCurrentAppBroadcastingChanged>;
        [[nodiscard]] IsCurrentAppBroadcastingChanged_revoker IsCurrentAppBroadcastingChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::AppBroadcasting::AppBroadcastingMonitor, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) IsCurrentAppBroadcastingChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Media::AppBroadcasting::IAppBroadcastingMonitor>
    {
        template <typename D> using type = consume_Windows_Media_AppBroadcasting_IAppBroadcastingMonitor<D>;
    };
    template <typename D>
    struct consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatus
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) CanStartBroadcast() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::AppBroadcasting::AppBroadcastingStatusDetails) Details() const;
    };
    template <> struct consume<llm:OS::Media::AppBroadcasting::IAppBroadcastingStatus>
    {
        template <typename D> using type = consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatus<D>;
    };
    template <typename D>
    struct consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatusDetails
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsAnyAppBroadcasting() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsCaptureResourceUnavailable() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsGameStreamInProgress() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsGpuConstrained() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsAppInactive() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsBlockedForApp() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsDisabledByUser() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsDisabledBySystem() const;
    };
    template <> struct consume<llm:OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails>
    {
        template <typename D> using type = consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatusDetails<D>;
    };
    template <typename D>
    struct consume_Windows_Media_AppBroadcasting_IAppBroadcastingUI
    {
        LLM_IMPL_AUTO(llm:OS::Media::AppBroadcasting::AppBroadcastingStatus) GetStatus() const;
        LLM_IMPL_AUTO(void) ShowBroadcastUI() const;
    };
    template <> struct consume<llm:OS::Media::AppBroadcasting::IAppBroadcastingUI>
    {
        template <typename D> using type = consume_Windows_Media_AppBroadcasting_IAppBroadcastingUI<D>;
    };
    template <typename D>
    struct consume_Windows_Media_AppBroadcasting_IAppBroadcastingUIStatics
    {
        LLM_IMPL_AUTO(llm:OS::Media::AppBroadcasting::AppBroadcastingUI) GetDefault() const;
        LLM_IMPL_AUTO(llm:OS::Media::AppBroadcasting::AppBroadcastingUI) GetForUser(llm:OS::System::User const& user) const;
    };
    template <> struct consume<llm:OS::Media::AppBroadcasting::IAppBroadcastingUIStatics>
    {
        template <typename D> using type = consume_Windows_Media_AppBroadcasting_IAppBroadcastingUIStatics<D>;
    };
}
#endif
