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
#ifndef LLM_OS_Devices_Geolocation_Geofencing_0_H
#define LLM_OS_Devices_Geolocation_Geofencing_0_H
LLM_EXPORT namespace llm::OS::Devices::Geolocation
{
    struct Geoposition;
    struct IGeoshape;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm::OS::Devices::Geolocation::Geofencing
{
    enum class GeofenceMonitorStatus : int32_t
    {
        Ready = 0,
        Initializing = 1,
        NoData = 2,
        Disabled = 3,
        NotInitialized = 4,
        NotAvailable = 5,
    };
    enum class GeofenceRemovalReason : int32_t
    {
        Used = 0,
        Expired = 1,
    };
    enum class GeofenceState : uint32_t
    {
        None = 0,
        Entered = 0x1,
        Exited = 0x2,
        Removed = 0x4,
    };
    enum class MonitoredGeofenceStates : uint32_t
    {
        None = 0,
        Entered = 0x1,
        Exited = 0x2,
        Removed = 0x4,
    };
    struct IGeofence;
    struct IGeofenceFactory;
    struct IGeofenceMonitor;
    struct IGeofenceMonitorStatics;
    struct IGeofenceStateChangeReport;
    struct Geofence;
    struct GeofenceMonitor;
    struct GeofenceStateChangeReport;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::Geolocation::Geofencing::IGeofence>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Geolocation::Geofencing::IGeofenceFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Geolocation::Geofencing::IGeofenceMonitor>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Geolocation::Geofencing::IGeofenceMonitorStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Geolocation::Geofencing::IGeofenceStateChangeReport>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Geolocation::Geofencing::Geofence>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Geolocation::Geofencing::GeofenceMonitor>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Geolocation::Geofencing::GeofenceStateChangeReport>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Geolocation::Geofencing::GeofenceMonitorStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Geolocation::Geofencing::GeofenceRemovalReason>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Geolocation::Geofencing::GeofenceState>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Geolocation::Geofencing::MonitoredGeofenceStates>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::Geolocation::Geofencing::Geofence> = L"Windows.Devices.Geolocation.Geofencing.Geofence";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Geolocation::Geofencing::GeofenceMonitor> = L"Windows.Devices.Geolocation.Geofencing.GeofenceMonitor";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Geolocation::Geofencing::GeofenceStateChangeReport> = L"Windows.Devices.Geolocation.Geofencing.GeofenceStateChangeReport";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Geolocation::Geofencing::GeofenceMonitorStatus> = L"Windows.Devices.Geolocation.Geofencing.GeofenceMonitorStatus";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Geolocation::Geofencing::GeofenceRemovalReason> = L"Windows.Devices.Geolocation.Geofencing.GeofenceRemovalReason";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Geolocation::Geofencing::GeofenceState> = L"Windows.Devices.Geolocation.Geofencing.GeofenceState";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Geolocation::Geofencing::MonitoredGeofenceStates> = L"Windows.Devices.Geolocation.Geofencing.MonitoredGeofenceStates";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Geolocation::Geofencing::IGeofence> = L"Windows.Devices.Geolocation.Geofencing.IGeofence";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Geolocation::Geofencing::IGeofenceFactory> = L"Windows.Devices.Geolocation.Geofencing.IGeofenceFactory";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Geolocation::Geofencing::IGeofenceMonitor> = L"Windows.Devices.Geolocation.Geofencing.IGeofenceMonitor";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Geolocation::Geofencing::IGeofenceMonitorStatics> = L"Windows.Devices.Geolocation.Geofencing.IGeofenceMonitorStatics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Geolocation::Geofencing::IGeofenceStateChangeReport> = L"Windows.Devices.Geolocation.Geofencing.IGeofenceStateChangeReport";
    template <> inline constexpr guid guid_v<llm::OS::Devices::Geolocation::Geofencing::IGeofence>{ 0x9C090823,0xEDB8,0x47E0,{ 0x82,0x45,0x5B,0xF6,0x1D,0x32,0x1F,0x2D } }; // 9C090823-EDB8-47E0-8245-5BF61D321F2D
    template <> inline constexpr guid guid_v<llm::OS::Devices::Geolocation::Geofencing::IGeofenceFactory>{ 0x841F624B,0x325F,0x4B90,{ 0xBC,0xA7,0x2B,0x80,0x22,0xA9,0x37,0x96 } }; // 841F624B-325F-4B90-BCA7-2B8022A93796
    template <> inline constexpr guid guid_v<llm::OS::Devices::Geolocation::Geofencing::IGeofenceMonitor>{ 0x4C0F5F78,0x1C1F,0x4621,{ 0xBB,0xBD,0x83,0x3B,0x92,0x24,0x72,0x26 } }; // 4C0F5F78-1C1F-4621-BBBD-833B92247226
    template <> inline constexpr guid guid_v<llm::OS::Devices::Geolocation::Geofencing::IGeofenceMonitorStatics>{ 0x2DD32FCF,0x7E75,0x4899,{ 0xAC,0xE3,0x2B,0xD0,0xA6,0x5C,0xCE,0x06 } }; // 2DD32FCF-7E75-4899-ACE3-2BD0A65CCE06
    template <> inline constexpr guid guid_v<llm::OS::Devices::Geolocation::Geofencing::IGeofenceStateChangeReport>{ 0x9A243C18,0x2464,0x4C89,{ 0xBE,0x05,0xB3,0xFF,0xFF,0x5B,0xAB,0xC5 } }; // 9A243C18-2464-4C89-BE05-B3FFFF5BABC5
    template <> struct default_interface<llm::OS::Devices::Geolocation::Geofencing::Geofence>{ using type = llm::OS::Devices::Geolocation::Geofencing::IGeofence; };
    template <> struct default_interface<llm::OS::Devices::Geolocation::Geofencing::GeofenceMonitor>{ using type = llm::OS::Devices::Geolocation::Geofencing::IGeofenceMonitor; };
    template <> struct default_interface<llm::OS::Devices::Geolocation::Geofencing::GeofenceStateChangeReport>{ using type = llm::OS::Devices::Geolocation::Geofencing::IGeofenceStateChangeReport; };
    template <> struct abi<llm::OS::Devices::Geolocation::Geofencing::IGeofence>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_StartTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Duration(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_DwellTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_MonitoredStates(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Geoshape(void**) noexcept = 0;
            virtual int32_t __stdcall get_SingleUse(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Geolocation::Geofencing::IGeofenceFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithMonitorStates(void*, void*, uint32_t, bool, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithMonitorStatesAndDwellTime(void*, void*, uint32_t, bool, int64_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithMonitorStatesDwellTimeStartTimeAndDuration(void*, void*, uint32_t, bool, int64_t, int64_t, int64_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Geolocation::Geofencing::IGeofenceMonitor>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Geofences(void**) noexcept = 0;
            virtual int32_t __stdcall get_LastKnownGeoposition(void**) noexcept = 0;
            virtual int32_t __stdcall add_GeofenceStateChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_GeofenceStateChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall ReadReports(void**) noexcept = 0;
            virtual int32_t __stdcall add_StatusChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_StatusChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Geolocation::Geofencing::IGeofenceMonitorStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Current(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Geolocation::Geofencing::IGeofenceStateChangeReport>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_NewState(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Geofence(void**) noexcept = 0;
            virtual int32_t __stdcall get_Geoposition(void**) noexcept = 0;
            virtual int32_t __stdcall get_RemovalReason(int32_t*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Geolocation_Geofencing_IGeofence
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) StartTime() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) Duration() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) DwellTime() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geofencing::MonitoredGeofenceStates) MonitoredStates() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::IGeoshape) Geoshape() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) SingleUse() const;
    };
    template <> struct consume<llm::OS::Devices::Geolocation::Geofencing::IGeofence>
    {
        template <typename D> using type = consume_Windows_Devices_Geolocation_Geofencing_IGeofence<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Geolocation_Geofencing_IGeofenceFactory
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geofencing::Geofence) Create(param::hstring const& id, llm::OS::Devices::Geolocation::IGeoshape const& geoshape) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geofencing::Geofence) CreateWithMonitorStates(param::hstring const& id, llm::OS::Devices::Geolocation::IGeoshape const& geoshape, llm::OS::Devices::Geolocation::Geofencing::MonitoredGeofenceStates const& monitoredStates, bool singleUse) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geofencing::Geofence) CreateWithMonitorStatesAndDwellTime(param::hstring const& id, llm::OS::Devices::Geolocation::IGeoshape const& geoshape, llm::OS::Devices::Geolocation::Geofencing::MonitoredGeofenceStates const& monitoredStates, bool singleUse, llm::OS::Foundation::TimeSpan const& dwellTime) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geofencing::Geofence) CreateWithMonitorStatesDwellTimeStartTimeAndDuration(param::hstring const& id, llm::OS::Devices::Geolocation::IGeoshape const& geoshape, llm::OS::Devices::Geolocation::Geofencing::MonitoredGeofenceStates const& monitoredStates, bool singleUse, llm::OS::Foundation::TimeSpan const& dwellTime, llm::OS::Foundation::DateTime const& startTime, llm::OS::Foundation::TimeSpan const& duration) const;
    };
    template <> struct consume<llm::OS::Devices::Geolocation::Geofencing::IGeofenceFactory>
    {
        template <typename D> using type = consume_Windows_Devices_Geolocation_Geofencing_IGeofenceFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Geolocation_Geofencing_IGeofenceMonitor
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geofencing::GeofenceMonitorStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Geolocation::Geofencing::Geofence>) Geofences() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geoposition) LastKnownGeoposition() const;
        LLM_IMPL_AUTO(llm::event_token) GeofenceStateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Geolocation::Geofencing::GeofenceMonitor, llm::OS::Foundation::IInspectable> const& eventHandler) const;
        using GeofenceStateChanged_revoker = impl::event_revoker<llm::OS::Devices::Geolocation::Geofencing::IGeofenceMonitor, &impl::abi_t<llm::OS::Devices::Geolocation::Geofencing::IGeofenceMonitor>::remove_GeofenceStateChanged>;
        [[nodiscard]] GeofenceStateChanged_revoker GeofenceStateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Geolocation::Geofencing::GeofenceMonitor, llm::OS::Foundation::IInspectable> const& eventHandler) const;
        LLM_IMPL_AUTO(void) GeofenceStateChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Geolocation::Geofencing::GeofenceStateChangeReport>) ReadReports() const;
        LLM_IMPL_AUTO(llm::event_token) StatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Geolocation::Geofencing::GeofenceMonitor, llm::OS::Foundation::IInspectable> const& eventHandler) const;
        using StatusChanged_revoker = impl::event_revoker<llm::OS::Devices::Geolocation::Geofencing::IGeofenceMonitor, &impl::abi_t<llm::OS::Devices::Geolocation::Geofencing::IGeofenceMonitor>::remove_StatusChanged>;
        [[nodiscard]] StatusChanged_revoker StatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Geolocation::Geofencing::GeofenceMonitor, llm::OS::Foundation::IInspectable> const& eventHandler) const;
        LLM_IMPL_AUTO(void) StatusChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::Devices::Geolocation::Geofencing::IGeofenceMonitor>
    {
        template <typename D> using type = consume_Windows_Devices_Geolocation_Geofencing_IGeofenceMonitor<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Geolocation_Geofencing_IGeofenceMonitorStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geofencing::GeofenceMonitor) Current() const;
    };
    template <> struct consume<llm::OS::Devices::Geolocation::Geofencing::IGeofenceMonitorStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Geolocation_Geofencing_IGeofenceMonitorStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Geolocation_Geofencing_IGeofenceStateChangeReport
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geofencing::GeofenceState) NewState() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geofencing::Geofence) Geofence() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geoposition) Geoposition() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geofencing::GeofenceRemovalReason) RemovalReason() const;
    };
    template <> struct consume<llm::OS::Devices::Geolocation::Geofencing::IGeofenceStateChangeReport>
    {
        template <typename D> using type = consume_Windows_Devices_Geolocation_Geofencing_IGeofenceStateChangeReport<D>;
    };
}
#endif
