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
#ifndef LLM_OS_ApplicationModel_LockScreen_0_H
#define LLM_OS_ApplicationModel_LockScreen_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct EventRegistrationToken;
    template <typename T> struct __declspec(empty_bases) IReference;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct IRandomAccessStream;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::LockScreen
{
    struct ILockApplicationHost;
    struct ILockApplicationHostStatics;
    struct ILockScreenBadge;
    struct ILockScreenInfo;
    struct ILockScreenUnlockingDeferral;
    struct ILockScreenUnlockingEventArgs;
    struct LockApplicationHost;
    struct LockScreenBadge;
    struct LockScreenInfo;
    struct LockScreenUnlockingDeferral;
    struct LockScreenUnlockingEventArgs;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::LockScreen::ILockApplicationHost>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::LockScreen::ILockApplicationHostStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::LockScreen::ILockScreenBadge>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::LockScreen::ILockScreenInfo>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::LockScreen::LockApplicationHost>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::LockScreen::LockScreenBadge>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::LockScreen::LockScreenInfo>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::LockScreen::LockScreenUnlockingDeferral>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::LockScreen::LockApplicationHost> = L"Windows.ApplicationModel.LockScreen.LockApplicationHost";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::LockScreen::LockScreenBadge> = L"Windows.ApplicationModel.LockScreen.LockScreenBadge";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::LockScreen::LockScreenInfo> = L"Windows.ApplicationModel.LockScreen.LockScreenInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::LockScreen::LockScreenUnlockingDeferral> = L"Windows.ApplicationModel.LockScreen.LockScreenUnlockingDeferral";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs> = L"Windows.ApplicationModel.LockScreen.LockScreenUnlockingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::LockScreen::ILockApplicationHost> = L"Windows.ApplicationModel.LockScreen.ILockApplicationHost";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::LockScreen::ILockApplicationHostStatics> = L"Windows.ApplicationModel.LockScreen.ILockApplicationHostStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::LockScreen::ILockScreenBadge> = L"Windows.ApplicationModel.LockScreen.ILockScreenBadge";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::LockScreen::ILockScreenInfo> = L"Windows.ApplicationModel.LockScreen.ILockScreenInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral> = L"Windows.ApplicationModel.LockScreen.ILockScreenUnlockingDeferral";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs> = L"Windows.ApplicationModel.LockScreen.ILockScreenUnlockingEventArgs";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::LockScreen::ILockApplicationHost>{ 0x38EE31AD,0xD94F,0x4E7C,{ 0x81,0xFA,0x4F,0x44,0x36,0x50,0x62,0x81 } }; // 38EE31AD-D94F-4E7C-81FA-4F4436506281
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::LockScreen::ILockApplicationHostStatics>{ 0xF48FAB8E,0x23D7,0x4E63,{ 0x96,0xA1,0x66,0x6F,0xF5,0x2D,0x3B,0x2C } }; // F48FAB8E-23D7-4E63-96A1-666FF52D3B2C
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::LockScreen::ILockScreenBadge>{ 0xE95105D9,0x2BFF,0x4DB0,{ 0x9B,0x4F,0x38,0x24,0x77,0x8B,0x9C,0x9A } }; // E95105D9-2BFF-4DB0-9B4F-3824778B9C9A
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::LockScreen::ILockScreenInfo>{ 0xF59AA65C,0x9711,0x4DC9,{ 0xA6,0x30,0x95,0xB6,0xCB,0x8C,0xDA,0xD0 } }; // F59AA65C-9711-4DC9-A630-95B6CB8CDAD0
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral>{ 0x7E7D1AD6,0x5203,0x43E7,{ 0x9B,0xD6,0x7C,0x39,0x47,0xD1,0xE3,0xFE } }; // 7E7D1AD6-5203-43E7-9BD6-7C3947D1E3FE
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs>{ 0x44E6C007,0x75FB,0x4ABB,{ 0x9F,0x8B,0x82,0x47,0x48,0x90,0x0C,0x71 } }; // 44E6C007-75FB-4ABB-9F8B-824748900C71
    template <> struct default_interface<llm::OS::ApplicationModel::LockScreen::LockApplicationHost>{ using type = llm::OS::ApplicationModel::LockScreen::ILockApplicationHost; };
    template <> struct default_interface<llm::OS::ApplicationModel::LockScreen::LockScreenBadge>{ using type = llm::OS::ApplicationModel::LockScreen::ILockScreenBadge; };
    template <> struct default_interface<llm::OS::ApplicationModel::LockScreen::LockScreenInfo>{ using type = llm::OS::ApplicationModel::LockScreen::ILockScreenInfo; };
    template <> struct default_interface<llm::OS::ApplicationModel::LockScreen::LockScreenUnlockingDeferral>{ using type = llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral; };
    template <> struct default_interface<llm::OS::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs>{ using type = llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs; };
    template <> struct abi<llm::OS::ApplicationModel::LockScreen::ILockApplicationHost>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestUnlock() noexcept = 0;
            virtual int32_t __stdcall add_Unlocking(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Unlocking(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::LockScreen::ILockApplicationHostStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForCurrentView(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::LockScreen::ILockScreenBadge>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Logo(void**) noexcept = 0;
            virtual int32_t __stdcall get_Glyph(void**) noexcept = 0;
            virtual int32_t __stdcall get_Number(void**) noexcept = 0;
            virtual int32_t __stdcall get_AutomationName(void**) noexcept = 0;
            virtual int32_t __stdcall LaunchApp() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::LockScreen::ILockScreenInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_LockScreenImageChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_LockScreenImageChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_LockScreenImage(void**) noexcept = 0;
            virtual int32_t __stdcall add_BadgesChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_BadgesChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_Badges(void**) noexcept = 0;
            virtual int32_t __stdcall add_DetailTextChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_DetailTextChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_DetailText(void**) noexcept = 0;
            virtual int32_t __stdcall add_AlarmIconChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AlarmIconChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_AlarmIcon(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Complete() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
            virtual int32_t __stdcall get_Deadline(int64_t*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_LockScreen_ILockApplicationHost
    {
        LLM_IMPL_AUTO(void) RequestUnlock() const;
        LLM_IMPL_AUTO(llm::event_token) Unlocking(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockApplicationHost, llm::OS::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs> const& handler) const;
        using Unlocking_revoker = impl::event_revoker<llm::OS::ApplicationModel::LockScreen::ILockApplicationHost, &impl::abi_t<llm::OS::ApplicationModel::LockScreen::ILockApplicationHost>::remove_Unlocking>;
        [[nodiscard]] Unlocking_revoker Unlocking(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockApplicationHost, llm::OS::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Unlocking(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::ApplicationModel::LockScreen::ILockApplicationHost>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_LockScreen_ILockApplicationHost<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_LockScreen_ILockApplicationHostStatics
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::LockScreen::LockApplicationHost) GetForCurrentView() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::LockScreen::ILockApplicationHostStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_LockScreen_ILockApplicationHostStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_LockScreen_ILockScreenBadge
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStream) Logo() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStream) Glyph() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) Number() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AutomationName() const;
        LLM_IMPL_AUTO(void) LaunchApp() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::LockScreen::ILockScreenBadge>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_LockScreen_ILockScreenBadge<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo
    {
        LLM_IMPL_AUTO(llm::event_token) LockScreenImageChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const& handler) const;
        using LockScreenImageChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::LockScreen::ILockScreenInfo, &impl::abi_t<llm::OS::ApplicationModel::LockScreen::ILockScreenInfo>::remove_LockScreenImageChanged>;
        [[nodiscard]] LockScreenImageChanged_revoker LockScreenImageChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) LockScreenImageChanged(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStream) LockScreenImage() const;
        LLM_IMPL_AUTO(llm::event_token) BadgesChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const& handler) const;
        using BadgesChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::LockScreen::ILockScreenInfo, &impl::abi_t<llm::OS::ApplicationModel::LockScreen::ILockScreenInfo>::remove_BadgesChanged>;
        [[nodiscard]] BadgesChanged_revoker BadgesChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) BadgesChanged(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::LockScreen::LockScreenBadge>) Badges() const;
        LLM_IMPL_AUTO(llm::event_token) DetailTextChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const& handler) const;
        using DetailTextChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::LockScreen::ILockScreenInfo, &impl::abi_t<llm::OS::ApplicationModel::LockScreen::ILockScreenInfo>::remove_DetailTextChanged>;
        [[nodiscard]] DetailTextChanged_revoker DetailTextChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) DetailTextChanged(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) DetailText() const;
        LLM_IMPL_AUTO(llm::event_token) AlarmIconChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const& handler) const;
        using AlarmIconChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::LockScreen::ILockScreenInfo, &impl::abi_t<llm::OS::ApplicationModel::LockScreen::ILockScreenInfo>::remove_AlarmIconChanged>;
        [[nodiscard]] AlarmIconChanged_revoker AlarmIconChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) AlarmIconChanged(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStream) AlarmIcon() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::LockScreen::ILockScreenInfo>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_LockScreen_ILockScreenUnlockingDeferral
    {
        LLM_IMPL_AUTO(void) Complete() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_LockScreen_ILockScreenUnlockingDeferral<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_LockScreen_ILockScreenUnlockingEventArgs
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::LockScreen::LockScreenUnlockingDeferral) GetDeferral() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) Deadline() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_LockScreen_ILockScreenUnlockingEventArgs<D>;
    };
}
#endif
