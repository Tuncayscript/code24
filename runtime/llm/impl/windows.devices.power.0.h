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
#ifndef LLM_OS_Devices_Power_0_H
#define LLM_OS_Devices_Power_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm::OS::System::Power
{
    enum class BatteryStatus : int32_t;
}
LLM_EXPORT namespace llm::OS::Devices::Power
{
    struct IBattery;
    struct IBatteryReport;
    struct IBatteryStatics;
    struct Battery;
    struct BatteryReport;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::Power::IBattery>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Power::IBatteryReport>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Power::IBatteryStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Power::Battery>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Power::BatteryReport>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::Power::Battery> = L"Windows.Devices.Power.Battery";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Power::BatteryReport> = L"Windows.Devices.Power.BatteryReport";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Power::IBattery> = L"Windows.Devices.Power.IBattery";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Power::IBatteryReport> = L"Windows.Devices.Power.IBatteryReport";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Power::IBatteryStatics> = L"Windows.Devices.Power.IBatteryStatics";
    template <> inline constexpr guid guid_v<llm::OS::Devices::Power::IBattery>{ 0xBC894FC6,0x0072,0x47C8,{ 0x8B,0x5D,0x61,0x4A,0xAA,0x7A,0x43,0x7E } }; // BC894FC6-0072-47C8-8B5D-614AAA7A437E
    template <> inline constexpr guid guid_v<llm::OS::Devices::Power::IBatteryReport>{ 0xC9858C3A,0x4E13,0x420A,{ 0xA8,0xD0,0x24,0xF1,0x8F,0x39,0x54,0x01 } }; // C9858C3A-4E13-420A-A8D0-24F18F395401
    template <> inline constexpr guid guid_v<llm::OS::Devices::Power::IBatteryStatics>{ 0x79CD72B6,0x9E5E,0x4452,{ 0xBE,0xA6,0xDF,0xCD,0x54,0x1E,0x59,0x7F } }; // 79CD72B6-9E5E-4452-BEA6-DFCD541E597F
    template <> struct default_interface<llm::OS::Devices::Power::Battery>{ using type = llm::OS::Devices::Power::IBattery; };
    template <> struct default_interface<llm::OS::Devices::Power::BatteryReport>{ using type = llm::OS::Devices::Power::IBatteryReport; };
    template <> struct abi<llm::OS::Devices::Power::IBattery>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DeviceId(void**) noexcept = 0;
            virtual int32_t __stdcall GetReport(void**) noexcept = 0;
            virtual int32_t __stdcall add_ReportUpdated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ReportUpdated(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Power::IBatteryReport>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ChargeRateInMilliwatts(void**) noexcept = 0;
            virtual int32_t __stdcall get_DesignCapacityInMilliwattHours(void**) noexcept = 0;
            virtual int32_t __stdcall get_FullChargeCapacityInMilliwattHours(void**) noexcept = 0;
            virtual int32_t __stdcall get_RemainingCapacityInMilliwattHours(void**) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Power::IBatteryStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AggregateBattery(void**) noexcept = 0;
            virtual int32_t __stdcall FromIdAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetDeviceSelector(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Power_IBattery
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DeviceId() const;
        LLM_IMPL_AUTO(llm::OS::Devices::Power::BatteryReport) GetReport() const;
        LLM_IMPL_AUTO(llm::event_token) ReportUpdated(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Power::Battery, llm::OS::Foundation::IInspectable> const& handler) const;
        using ReportUpdated_revoker = impl::event_revoker<llm::OS::Devices::Power::IBattery, &impl::abi_t<llm::OS::Devices::Power::IBattery>::remove_ReportUpdated>;
        [[nodiscard]] ReportUpdated_revoker ReportUpdated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Power::Battery, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) ReportUpdated(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::Devices::Power::IBattery>
    {
        template <typename D> using type = consume_Windows_Devices_Power_IBattery<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Power_IBatteryReport
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) ChargeRateInMilliwatts() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) DesignCapacityInMilliwattHours() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) FullChargeCapacityInMilliwattHours() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) RemainingCapacityInMilliwattHours() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::System::Power::BatteryStatus) Status() const;
    };
    template <> struct consume<llm::OS::Devices::Power::IBatteryReport>
    {
        template <typename D> using type = consume_Windows_Devices_Power_IBatteryReport<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Power_IBatteryStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Power::Battery) AggregateBattery() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Power::Battery>) FromIdAsync(param::hstring const& deviceId) const;
        LLM_IMPL_AUTO(hstring) GetDeviceSelector() const;
    };
    template <> struct consume<llm::OS::Devices::Power::IBatteryStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Power_IBatteryStatics<D>;
    };
}
#endif
