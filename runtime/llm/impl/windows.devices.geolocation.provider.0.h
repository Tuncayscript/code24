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
#ifndef LLM_OS_Devices_Geolocation_Provider_0_H
#define LLM_OS_Devices_Geolocation_Provider_0_H
LLM_EXPORT namespace llm::OS::Devices::Geolocation
{
    struct BasicGeoposition;
    enum class PositionSource : int32_t;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    template <typename T> struct __declspec(empty_bases) EventHandler;
    struct EventRegistrationToken;
}
LLM_EXPORT namespace llm::OS::Devices::Geolocation::Provider
{
    enum class LocationOverrideStatus : int32_t
    {
        Success = 0,
        AccessDenied = 1,
        AlreadyStarted = 2,
        Other = 3,
    };
    struct IGeolocationProvider;
    struct GeolocationProvider;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::Geolocation::Provider::IGeolocationProvider>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Geolocation::Provider::GeolocationProvider>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Geolocation::Provider::LocationOverrideStatus>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::Geolocation::Provider::GeolocationProvider> = L"Windows.Devices.Geolocation.Provider.GeolocationProvider";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Geolocation::Provider::LocationOverrideStatus> = L"Windows.Devices.Geolocation.Provider.LocationOverrideStatus";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Geolocation::Provider::IGeolocationProvider> = L"Windows.Devices.Geolocation.Provider.IGeolocationProvider";
    template <> inline constexpr guid guid_v<llm::OS::Devices::Geolocation::Provider::IGeolocationProvider>{ 0xE4CF071D,0x3F64,0x509F,{ 0x8D,0xC2,0x0B,0x74,0xA0,0x59,0x82,0x9D } }; // E4CF071D-3F64-509F-8DC2-0B74A059829D
    template <> struct default_interface<llm::OS::Devices::Geolocation::Provider::GeolocationProvider>{ using type = llm::OS::Devices::Geolocation::Provider::IGeolocationProvider; };
    template <> struct abi<llm::OS::Devices::Geolocation::Provider::IGeolocationProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsOverridden(bool*) noexcept = 0;
            virtual int32_t __stdcall SetOverridePosition(struct struct_Windows_Devices_Geolocation_BasicGeoposition, int32_t, double, int32_t*) noexcept = 0;
            virtual int32_t __stdcall ClearOverridePosition() noexcept = 0;
            virtual int32_t __stdcall add_IsOverriddenChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_IsOverriddenChanged(llm::event_token) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Geolocation_Provider_IGeolocationProvider
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsOverridden() const;
        LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Provider::LocationOverrideStatus) SetOverridePosition(llm::OS::Devices::Geolocation::BasicGeoposition const& newPosition, llm::OS::Devices::Geolocation::PositionSource const& positionSource, double accuracyInMeters) const;
        LLM_IMPL_AUTO(void) ClearOverridePosition() const;
        LLM_IMPL_AUTO(llm::event_token) IsOverriddenChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const;
        using IsOverriddenChanged_revoker = impl::event_revoker<llm::OS::Devices::Geolocation::Provider::IGeolocationProvider, &impl::abi_t<llm::OS::Devices::Geolocation::Provider::IGeolocationProvider>::remove_IsOverriddenChanged>;
        [[nodiscard]] IsOverriddenChanged_revoker IsOverriddenChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) IsOverriddenChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::Devices::Geolocation::Provider::IGeolocationProvider>
    {
        template <typename D> using type = consume_Windows_Devices_Geolocation_Provider_IGeolocationProvider<D>;
    };
}
#endif
