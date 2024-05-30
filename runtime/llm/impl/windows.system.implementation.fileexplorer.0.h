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
#ifndef LLM_OS_System_Implementation_FileExplorer_0_H
#define LLM_OS_System_Implementation_FileExplorer_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Web::Http
{
    struct HttpRequestMessage;
    struct HttpResponseMessage;
}
LLM_EXPORT namespace llm:OS::System::Implementation::FileExplorer
{
    struct ISysStorageProviderEventReceivedEventArgs;
    struct ISysStorageProviderEventReceivedEventArgsFactory;
    struct ISysStorageProviderEventSource;
    struct ISysStorageProviderHandlerFactory;
    struct ISysStorageProviderHttpRequestProvider;
    struct SysStorageProviderEventReceivedEventArgs;
}
namespace llm::impl
{
    template <> struct category<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgsFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderHandlerFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderHttpRequestProvider>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Implementation::FileExplorer::SysStorageProviderEventReceivedEventArgs>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::System::Implementation::FileExplorer::SysStorageProviderEventReceivedEventArgs> = L"Windows.System.Implementation.FileExplorer.SysStorageProviderEventReceivedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgs> = L"Windows.System.Implementation.FileExplorer.ISysStorageProviderEventReceivedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgsFactory> = L"Windows.System.Implementation.FileExplorer.ISysStorageProviderEventReceivedEventArgsFactory";
    template <> inline constexpr auto& name_v<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource> = L"Windows.System.Implementation.FileExplorer.ISysStorageProviderEventSource";
    template <> inline constexpr auto& name_v<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderHandlerFactory> = L"Windows.System.Implementation.FileExplorer.ISysStorageProviderHandlerFactory";
    template <> inline constexpr auto& name_v<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderHttpRequestProvider> = L"Windows.System.Implementation.FileExplorer.ISysStorageProviderHttpRequestProvider";
    template <> inline constexpr guid guid_v<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgs>{ 0xE132D1B9,0x7B9D,0x5820,{ 0x97,0x28,0x42,0x62,0xB5,0x28,0x91,0x42 } }; // E132D1B9-7B9D-5820-9728-4262B5289142
    template <> inline constexpr guid guid_v<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgsFactory>{ 0xDE1A780E,0xE975,0x5F68,{ 0xBC,0xC6,0xFB,0x46,0x28,0x1C,0x6A,0x61 } }; // DE1A780E-E975-5F68-BCC6-FB46281C6A61
    template <> inline constexpr guid guid_v<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource>{ 0x1F36C476,0x9546,0x536A,{ 0x83,0x81,0x2F,0x9A,0x2C,0x08,0xCE,0xDD } }; // 1F36C476-9546-536A-8381-2F9A2C08CEDD
    template <> inline constexpr guid guid_v<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderHandlerFactory>{ 0xEE798431,0x8213,0x5E89,{ 0xA6,0x23,0x14,0xD8,0xC7,0x2B,0x8A,0x61 } }; // EE798431-8213-5E89-A623-14D8C72B8A61
    template <> inline constexpr guid guid_v<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderHttpRequestProvider>{ 0xCB6FEFB6,0xE76A,0x5C25,{ 0xA3,0x3E,0x3E,0x78,0xA6,0xE0,0xE0,0xCE } }; // CB6FEFB6-E76A-5C25-A33E-3E78A6E0E0CE
    template <> struct default_interface<llm:OS::System::Implementation::FileExplorer::SysStorageProviderEventReceivedEventArgs>{ using type = llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgs; };
    template <> struct abi<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Json(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgsFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_EventReceived(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_EventReceived(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderHandlerFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetHttpRequestProvider(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetEventSource(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderHttpRequestProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SendRequestAsync(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderEventReceivedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Json() const;
    };
    template <> struct consume<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgs>
    {
        template <typename D> using type = consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderEventReceivedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderEventReceivedEventArgsFactory
    {
        LLM_IMPL_AUTO(llm:OS::System::Implementation::FileExplorer::SysStorageProviderEventReceivedEventArgs) CreateInstance(param::hstring const& json) const;
    };
    template <> struct consume<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgsFactory>
    {
        template <typename D> using type = consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderEventReceivedEventArgsFactory<D>;
    };
    template <typename D>
    struct consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderEventSource
    {
        LLM_IMPL_AUTO(llm::event_token) EventReceived(llm:OS::Foundation::TypedEventHandler<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource, llm:OS::System::Implementation::FileExplorer::SysStorageProviderEventReceivedEventArgs> const& handler) const;
        using EventReceived_revoker = impl::event_revoker<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource, &impl::abi_t<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource>::remove_EventReceived>;
        [[nodiscard]] EventReceived_revoker EventReceived(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource, llm:OS::System::Implementation::FileExplorer::SysStorageProviderEventReceivedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) EventReceived(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource>
    {
        template <typename D> using type = consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderEventSource<D>;
    };
    template <typename D>
    struct consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderHandlerFactory
    {
        LLM_IMPL_AUTO(llm:OS::System::Implementation::FileExplorer::ISysStorageProviderHttpRequestProvider) GetHttpRequestProvider(param::hstring const& syncRootId) const;
        LLM_IMPL_AUTO(llm:OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource) GetEventSource(param::hstring const& syncRootId, param::hstring const& eventName) const;
    };
    template <> struct consume<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderHandlerFactory>
    {
        template <typename D> using type = consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderHandlerFactory<D>;
    };
    template <typename D>
    struct consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderHttpRequestProvider
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Web::Http::HttpResponseMessage>) SendRequestAsync(llm:OS::Web::Http::HttpRequestMessage const& request) const;
    };
    template <> struct consume<llm:OS::System::Implementation::FileExplorer::ISysStorageProviderHttpRequestProvider>
    {
        template <typename D> using type = consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderHttpRequestProvider<D>;
    };
}
#endif
