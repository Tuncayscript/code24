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
#ifndef LLM_OS_Networking_ServiceDiscovery_Dnssd_0_H
#define LLM_OS_Networking_ServiceDiscovery_Dnssd_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename K, typename V> struct __declspec(empty_bases) IMap;
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Networking
{
    struct HostName;
}
LLM_EXPORT namespace llm:OS::Networking::Connectivity
{
    struct NetworkAdapter;
}
LLM_EXPORT namespace llm:OS::Networking::Sockets
{
    struct DatagramSocket;
    struct StreamSocketListener;
}
LLM_EXPORT namespace llm:OS::Networking::ServiceDiscovery::Dnssd
{
    enum class DnssdRegistrationStatus : int32_t
    {
        Success = 0,
        InvalidServiceName = 1,
        ServerError = 2,
        SecurityError = 3,
    };
    enum class DnssdServiceWatcherStatus : int32_t
    {
        Created = 0,
        Started = 1,
        EnumerationCompleted = 2,
        Stopping = 3,
        Stopped = 4,
        Aborted = 5,
    };
    struct IDnssdRegistrationResult;
    struct IDnssdServiceInstance;
    struct IDnssdServiceInstanceFactory;
    struct IDnssdServiceWatcher;
    struct DnssdRegistrationResult;
    struct DnssdServiceInstance;
    struct DnssdServiceInstanceCollection;
    struct DnssdServiceWatcher;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstanceFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstanceCollection>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcherStatus>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> = L"Windows.Networking.ServiceDiscovery.Dnssd.DnssdRegistrationResult";
    template <> inline constexpr auto& name_v<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance> = L"Windows.Networking.ServiceDiscovery.Dnssd.DnssdServiceInstance";
    template <> inline constexpr auto& name_v<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstanceCollection> = L"Windows.Networking.ServiceDiscovery.Dnssd.DnssdServiceInstanceCollection";
    template <> inline constexpr auto& name_v<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher> = L"Windows.Networking.ServiceDiscovery.Dnssd.DnssdServiceWatcher";
    template <> inline constexpr auto& name_v<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationStatus> = L"Windows.Networking.ServiceDiscovery.Dnssd.DnssdRegistrationStatus";
    template <> inline constexpr auto& name_v<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcherStatus> = L"Windows.Networking.ServiceDiscovery.Dnssd.DnssdServiceWatcherStatus";
    template <> inline constexpr auto& name_v<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult> = L"Windows.Networking.ServiceDiscovery.Dnssd.IDnssdRegistrationResult";
    template <> inline constexpr auto& name_v<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance> = L"Windows.Networking.ServiceDiscovery.Dnssd.IDnssdServiceInstance";
    template <> inline constexpr auto& name_v<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstanceFactory> = L"Windows.Networking.ServiceDiscovery.Dnssd.IDnssdServiceInstanceFactory";
    template <> inline constexpr auto& name_v<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher> = L"Windows.Networking.ServiceDiscovery.Dnssd.IDnssdServiceWatcher";
    template <> inline constexpr guid guid_v<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult>{ 0x3D786AD2,0xE606,0x5350,{ 0x73,0xEA,0x7E,0x97,0xF0,0x66,0x16,0x2F } }; // 3D786AD2-E606-5350-73EA-7E97F066162F
    template <> inline constexpr guid guid_v<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>{ 0xE246DB7E,0x98A5,0x4CA1,{ 0xB9,0xE4,0xC2,0x53,0xD3,0x3C,0x35,0xFF } }; // E246DB7E-98A5-4CA1-B9E4-C253D33C35FF
    template <> inline constexpr guid guid_v<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstanceFactory>{ 0x6CB061A1,0xC478,0x4331,{ 0x96,0x84,0x4A,0xF2,0x18,0x6C,0x0A,0x2B } }; // 6CB061A1-C478-4331-9684-4AF2186C0A2B
    template <> inline constexpr guid guid_v<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>{ 0xCC34D9C1,0xDB7D,0x4B69,{ 0x98,0x3D,0xC6,0xF8,0x3F,0x20,0x56,0x82 } }; // CC34D9C1-DB7D-4B69-983D-C6F83F205682
    template <> struct default_interface<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult>{ using type = llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult; };
    template <> struct default_interface<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance>{ using type = llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance; };
    template <> struct default_interface<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstanceCollection>{ using type = llm:OS::Foundation::Collections::IVectorView<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance>; };
    template <> struct default_interface<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher>{ using type = llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher; };
    template <> struct abi<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_IPAddress(void**) noexcept = 0;
            virtual int32_t __stdcall get_HasInstanceNameChanged(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DnssdServiceInstanceName(void**) noexcept = 0;
            virtual int32_t __stdcall put_DnssdServiceInstanceName(void*) noexcept = 0;
            virtual int32_t __stdcall get_HostName(void**) noexcept = 0;
            virtual int32_t __stdcall put_HostName(void*) noexcept = 0;
            virtual int32_t __stdcall get_Port(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall put_Port(uint16_t) noexcept = 0;
            virtual int32_t __stdcall get_Priority(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall put_Priority(uint16_t) noexcept = 0;
            virtual int32_t __stdcall get_Weight(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall put_Weight(uint16_t) noexcept = 0;
            virtual int32_t __stdcall get_TextAttributes(void**) noexcept = 0;
            virtual int32_t __stdcall RegisterStreamSocketListenerAsync1(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RegisterStreamSocketListenerAsync2(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall RegisterDatagramSocketAsync1(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RegisterDatagramSocketAsync2(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstanceFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void*, uint16_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_Added(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Added(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_EnumerationCompleted(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_EnumerationCompleted(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Stopped(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Stopped(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall Start() noexcept = 0;
            virtual int32_t __stdcall Stop() noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Networking_ServiceDiscovery_Dnssd_IDnssdRegistrationResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::HostName) IPAddress() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) HasInstanceNameChanged() const;
    };
    template <> struct consume<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult>
    {
        template <typename D> using type = consume_Windows_Networking_ServiceDiscovery_Dnssd_IDnssdRegistrationResult<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_ServiceDiscovery_Dnssd_IDnssdServiceInstance
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DnssdServiceInstanceName() const;
        LLM_IMPL_AUTO(void) DnssdServiceInstanceName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::HostName) HostName() const;
        LLM_IMPL_AUTO(void) HostName(llm:OS::Networking::HostName const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) Port() const;
        LLM_IMPL_AUTO(void) Port(uint16_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) Priority() const;
        LLM_IMPL_AUTO(void) Priority(uint16_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) Weight() const;
        LLM_IMPL_AUTO(void) Weight(uint16_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IMap<hstring, hstring>) TextAttributes() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult>) RegisterStreamSocketListenerAsync(llm:OS::Networking::Sockets::StreamSocketListener const& socket) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult>) RegisterStreamSocketListenerAsync(llm:OS::Networking::Sockets::StreamSocketListener const& socket, llm:OS::Networking::Connectivity::NetworkAdapter const& adapter) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult>) RegisterDatagramSocketAsync(llm:OS::Networking::Sockets::DatagramSocket const& socket) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult>) RegisterDatagramSocketAsync(llm:OS::Networking::Sockets::DatagramSocket const& socket, llm:OS::Networking::Connectivity::NetworkAdapter const& adapter) const;
    };
    template <> struct consume<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>
    {
        template <typename D> using type = consume_Windows_Networking_ServiceDiscovery_Dnssd_IDnssdServiceInstance<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_ServiceDiscovery_Dnssd_IDnssdServiceInstanceFactory
    {
        LLM_IMPL_AUTO(llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance) Create(param::hstring const& dnssdServiceInstanceName, llm:OS::Networking::HostName const& hostName, uint16_t port) const;
    };
    template <> struct consume<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstanceFactory>
    {
        template <typename D> using type = consume_Windows_Networking_ServiceDiscovery_Dnssd_IDnssdServiceInstanceFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_ServiceDiscovery_Dnssd_IDnssdServiceWatcher
    {
        LLM_IMPL_AUTO(llm::event_token) Added(llm:OS::Foundation::TypedEventHandler<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance> const& handler) const;
        using Added_revoker = impl::event_revoker<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher, &impl::abi_t<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>::remove_Added>;
        [[nodiscard]] Added_revoker Added(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance> const& handler) const;
        LLM_IMPL_AUTO(void) Added(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) EnumerationCompleted(llm:OS::Foundation::TypedEventHandler<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, llm:OS::Foundation::IInspectable> const& handler) const;
        using EnumerationCompleted_revoker = impl::event_revoker<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher, &impl::abi_t<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>::remove_EnumerationCompleted>;
        [[nodiscard]] EnumerationCompleted_revoker EnumerationCompleted(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) EnumerationCompleted(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Stopped(llm:OS::Foundation::TypedEventHandler<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, llm:OS::Foundation::IInspectable> const& handler) const;
        using Stopped_revoker = impl::event_revoker<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher, &impl::abi_t<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>::remove_Stopped>;
        [[nodiscard]] Stopped_revoker Stopped(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Stopped(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcherStatus) Status() const;
        LLM_IMPL_AUTO(void) Start() const;
        LLM_IMPL_AUTO(void) Stop() const;
    };
    template <> struct consume<llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>
    {
        template <typename D> using type = consume_Windows_Networking_ServiceDiscovery_Dnssd_IDnssdServiceWatcher<D>;
    };
}
#endif
