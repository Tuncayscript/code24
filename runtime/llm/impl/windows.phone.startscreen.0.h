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
#ifndef LLM_OS_Phone_StartScreen_0_H
#define LLM_OS_Phone_StartScreen_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm:OS::UI::Notifications
{
    struct BadgeUpdater;
    struct TileUpdater;
    struct ToastNotifier;
}
LLM_EXPORT namespace llm:OS::Phone::StartScreen
{
    struct IDualSimTile;
    struct IDualSimTileStatics;
    struct IToastNotificationManagerStatics3;
    struct DualSimTile;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Phone::StartScreen::IDualSimTile>{ using type = interface_category; };
    template <> struct category<llm:OS::Phone::StartScreen::IDualSimTileStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Phone::StartScreen::IToastNotificationManagerStatics3>{ using type = interface_category; };
    template <> struct category<llm:OS::Phone::StartScreen::DualSimTile>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::Phone::StartScreen::DualSimTile> = L"Windows.Phone.StartScreen.DualSimTile";
    template <> inline constexpr auto& name_v<llm:OS::Phone::StartScreen::IDualSimTile> = L"Windows.Phone.StartScreen.IDualSimTile";
    template <> inline constexpr auto& name_v<llm:OS::Phone::StartScreen::IDualSimTileStatics> = L"Windows.Phone.StartScreen.IDualSimTileStatics";
    template <> inline constexpr auto& name_v<llm:OS::Phone::StartScreen::IToastNotificationManagerStatics3> = L"Windows.Phone.StartScreen.IToastNotificationManagerStatics3";
    template <> inline constexpr guid guid_v<llm:OS::Phone::StartScreen::IDualSimTile>{ 0x143AB213,0xD05F,0x4041,{ 0xA1,0x8C,0x3E,0x3F,0xCB,0x75,0xB4,0x1E } }; // 143AB213-D05F-4041-A18C-3E3FCB75B41E
    template <> inline constexpr guid guid_v<llm:OS::Phone::StartScreen::IDualSimTileStatics>{ 0x50567C9E,0xC58F,0x4DC9,{ 0xB6,0xE8,0xFA,0x67,0x77,0xEE,0xEB,0x37 } }; // 50567C9E-C58F-4DC9-B6E8-FA6777EEEB37
    template <> inline constexpr guid guid_v<llm:OS::Phone::StartScreen::IToastNotificationManagerStatics3>{ 0x2717F54B,0x50DF,0x4455,{ 0x8E,0x6E,0x41,0xE0,0xFC,0x8E,0x13,0xCE } }; // 2717F54B-50DF-4455-8E6E-41E0FC8E13CE
    template <> struct default_interface<llm:OS::Phone::StartScreen::DualSimTile>{ using type = llm:OS::Phone::StartScreen::IDualSimTile; };
    template <> struct abi<llm:OS::Phone::StartScreen::IDualSimTile>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall put_DisplayName(void*) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsPinnedToStart(bool*) noexcept = 0;
            virtual int32_t __stdcall CreateAsync(void**) noexcept = 0;
            virtual int32_t __stdcall UpdateAsync(void**) noexcept = 0;
            virtual int32_t __stdcall DeleteAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Phone::StartScreen::IDualSimTileStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetTileForSim2(void**) noexcept = 0;
            virtual int32_t __stdcall UpdateDisplayNameForSim1Async(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateTileUpdaterForSim1(void**) noexcept = 0;
            virtual int32_t __stdcall CreateTileUpdaterForSim2(void**) noexcept = 0;
            virtual int32_t __stdcall CreateBadgeUpdaterForSim1(void**) noexcept = 0;
            virtual int32_t __stdcall CreateBadgeUpdaterForSim2(void**) noexcept = 0;
            virtual int32_t __stdcall CreateToastNotifierForSim1(void**) noexcept = 0;
            virtual int32_t __stdcall CreateToastNotifierForSim2(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Phone::StartScreen::IToastNotificationManagerStatics3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateToastNotifierForSecondaryTile(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Phone_StartScreen_IDualSimTile
    {
        LLM_IMPL_AUTO(void) DisplayName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsPinnedToStart() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) CreateAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) UpdateAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) DeleteAsync() const;
    };
    template <> struct consume<llm:OS::Phone::StartScreen::IDualSimTile>
    {
        template <typename D> using type = consume_Windows_Phone_StartScreen_IDualSimTile<D>;
    };
    template <typename D>
    struct consume_Windows_Phone_StartScreen_IDualSimTileStatics
    {
        LLM_IMPL_AUTO(llm:OS::Phone::StartScreen::DualSimTile) GetTileForSim2() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) UpdateDisplayNameForSim1Async(param::hstring const& name) const;
        LLM_IMPL_AUTO(llm:OS::UI::Notifications::TileUpdater) CreateTileUpdaterForSim1() const;
        LLM_IMPL_AUTO(llm:OS::UI::Notifications::TileUpdater) CreateTileUpdaterForSim2() const;
        LLM_IMPL_AUTO(llm:OS::UI::Notifications::BadgeUpdater) CreateBadgeUpdaterForSim1() const;
        LLM_IMPL_AUTO(llm:OS::UI::Notifications::BadgeUpdater) CreateBadgeUpdaterForSim2() const;
        LLM_IMPL_AUTO(llm:OS::UI::Notifications::ToastNotifier) CreateToastNotifierForSim1() const;
        LLM_IMPL_AUTO(llm:OS::UI::Notifications::ToastNotifier) CreateToastNotifierForSim2() const;
    };
    template <> struct consume<llm:OS::Phone::StartScreen::IDualSimTileStatics>
    {
        template <typename D> using type = consume_Windows_Phone_StartScreen_IDualSimTileStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Phone_StartScreen_IToastNotificationManagerStatics3
    {
        LLM_IMPL_AUTO(llm:OS::UI::Notifications::ToastNotifier) CreateToastNotifierForSecondaryTile(param::hstring const& tileId) const;
    };
    template <> struct consume<llm:OS::Phone::StartScreen::IToastNotificationManagerStatics3>
    {
        template <typename D> using type = consume_Windows_Phone_StartScreen_IToastNotificationManagerStatics3<D>;
    };
}
#endif
