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
#ifndef LLM_OS_Devices_Radios_0_H
#define LLM_OS_Devices_Radios_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm::OS::Devices::Radios
{
    enum class RadioAccessStatus : int32_t
    {
        Unspecified = 0,
        Allowed = 1,
        DeniedByUser = 2,
        DeniedBySystem = 3,
    };
    enum class RadioKind : int32_t
    {
        Other = 0,
        WiFi = 1,
        MobileBroadband = 2,
        Bluetooth = 3,
        FM = 4,
    };
    enum class RadioState : int32_t
    {
        Unknown = 0,
        On = 1,
        Off = 2,
        Disabled = 3,
    };
    struct IRadio;
    struct IRadioStatics;
    struct Radio;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::Radios::IRadio>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Radios::IRadioStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Radios::Radio>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Radios::RadioAccessStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Radios::RadioKind>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Radios::RadioState>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::Radios::Radio> = L"Windows.Devices.Radios.Radio";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Radios::RadioAccessStatus> = L"Windows.Devices.Radios.RadioAccessStatus";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Radios::RadioKind> = L"Windows.Devices.Radios.RadioKind";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Radios::RadioState> = L"Windows.Devices.Radios.RadioState";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Radios::IRadio> = L"Windows.Devices.Radios.IRadio";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Radios::IRadioStatics> = L"Windows.Devices.Radios.IRadioStatics";
    template <> inline constexpr guid guid_v<llm::OS::Devices::Radios::IRadio>{ 0x252118DF,0xB33E,0x416A,{ 0x87,0x5F,0x1C,0xF3,0x8A,0xE2,0xD8,0x3E } }; // 252118DF-B33E-416A-875F-1CF38AE2D83E
    template <> inline constexpr guid guid_v<llm::OS::Devices::Radios::IRadioStatics>{ 0x5FB6A12E,0x67CB,0x46AE,{ 0xAA,0xE9,0x65,0x91,0x9F,0x86,0xEF,0xF4 } }; // 5FB6A12E-67CB-46AE-AAE9-65919F86EFF4
    template <> struct default_interface<llm::OS::Devices::Radios::Radio>{ using type = llm::OS::Devices::Radios::IRadio; };
    template <> struct abi<llm::OS::Devices::Radios::IRadio>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetStateAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall add_StateChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_StateChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_State(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Radios::IRadioStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetRadiosAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetDeviceSelector(void**) noexcept = 0;
            virtual int32_t __stdcall FromIdAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestAccessAsync(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Radios_IRadio
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Radios::RadioAccessStatus>) SetStateAsync(llm::OS::Devices::Radios::RadioState const& value) const;
        LLM_IMPL_AUTO(llm::event_token) StateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Radios::Radio, llm::OS::Foundation::IInspectable> const& handler) const;
        using StateChanged_revoker = impl::event_revoker<llm::OS::Devices::Radios::IRadio, &impl::abi_t<llm::OS::Devices::Radios::IRadio>::remove_StateChanged>;
        [[nodiscard]] StateChanged_revoker StateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Radios::Radio, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) StateChanged(llm::event_token const& eventCookie) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Radios::RadioState) State() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Radios::RadioKind) Kind() const;
    };
    template <> struct consume<llm::OS::Devices::Radios::IRadio>
    {
        template <typename D> using type = consume_Windows_Devices_Radios_IRadio<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Radios_IRadioStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Radios::Radio>>) GetRadiosAsync() const;
        LLM_IMPL_AUTO(hstring) GetDeviceSelector() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Radios::Radio>) FromIdAsync(param::hstring const& deviceId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Radios::RadioAccessStatus>) RequestAccessAsync() const;
    };
    template <> struct consume<llm::OS::Devices::Radios::IRadioStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Radios_IRadioStatics<D>;
    };
}
#endif
