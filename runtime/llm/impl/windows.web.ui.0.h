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
#ifndef LLM_OS_Web_UI_0_H
#define LLM_OS_Web_UI_0_H
LLM_EXPORT namespace llm::OS::ApplicationModel::DataTransfer
{
    struct DataPackage;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    struct Deferral;
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
    struct Uri;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct IRandomAccessStream;
}
LLM_EXPORT namespace llm::OS::UI
{
    struct Color;
}
LLM_EXPORT namespace llm::OS::Web
{
    struct IUriToStreamResolver;
    enum class WebErrorStatus : int32_t;
}
LLM_EXPORT namespace llm::OS::Web::Http
{
    struct HttpRequestMessage;
    struct HttpResponseMessage;
}
LLM_EXPORT namespace llm::OS::Web::UI
{
    enum class WebViewControlPermissionState : int32_t
    {
        Unknown = 0,
        Defer = 1,
        Allow = 2,
        Deny = 3,
    };
    enum class WebViewControlPermissionType : int32_t
    {
        Geolocation = 0,
        UnlimitedIndexedDBQuota = 1,
        Media = 2,
        PointerLock = 3,
        WebNotifications = 4,
        Screen = 5,
        ImmersiveView = 6,
    };
    struct IWebViewControl;
    struct IWebViewControl2;
    struct IWebViewControlContentLoadingEventArgs;
    struct IWebViewControlDOMContentLoadedEventArgs;
    struct IWebViewControlDeferredPermissionRequest;
    struct IWebViewControlLongRunningScriptDetectedEventArgs;
    struct IWebViewControlNavigationCompletedEventArgs;
    struct IWebViewControlNavigationStartingEventArgs;
    struct IWebViewControlNewWindowRequestedEventArgs;
    struct IWebViewControlNewWindowRequestedEventArgs2;
    struct IWebViewControlPermissionRequest;
    struct IWebViewControlPermissionRequestedEventArgs;
    struct IWebViewControlScriptNotifyEventArgs;
    struct IWebViewControlSettings;
    struct IWebViewControlUnsupportedUriSchemeIdentifiedEventArgs;
    struct IWebViewControlUnviewableContentIdentifiedEventArgs;
    struct IWebViewControlWebResourceRequestedEventArgs;
    struct WebViewControlContentLoadingEventArgs;
    struct WebViewControlDOMContentLoadedEventArgs;
    struct WebViewControlDeferredPermissionRequest;
    struct WebViewControlLongRunningScriptDetectedEventArgs;
    struct WebViewControlNavigationCompletedEventArgs;
    struct WebViewControlNavigationStartingEventArgs;
    struct WebViewControlNewWindowRequestedEventArgs;
    struct WebViewControlPermissionRequest;
    struct WebViewControlPermissionRequestedEventArgs;
    struct WebViewControlScriptNotifyEventArgs;
    struct WebViewControlSettings;
    struct WebViewControlUnsupportedUriSchemeIdentifiedEventArgs;
    struct WebViewControlUnviewableContentIdentifiedEventArgs;
    struct WebViewControlWebResourceRequestedEventArgs;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Web::UI::IWebViewControl>{ using type = interface_category; };
    template <> struct category<llm::OS::Web::UI::IWebViewControl2>{ using type = interface_category; };
    template <> struct category<llm::OS::Web::UI::IWebViewControlContentLoadingEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Web::UI::IWebViewControlDOMContentLoadedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Web::UI::IWebViewControlDeferredPermissionRequest>{ using type = interface_category; };
    template <> struct category<llm::OS::Web::UI::IWebViewControlLongRunningScriptDetectedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Web::UI::IWebViewControlNavigationCompletedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Web::UI::IWebViewControlNavigationStartingEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Web::UI::IWebViewControlNewWindowRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Web::UI::IWebViewControlNewWindowRequestedEventArgs2>{ using type = interface_category; };
    template <> struct category<llm::OS::Web::UI::IWebViewControlPermissionRequest>{ using type = interface_category; };
    template <> struct category<llm::OS::Web::UI::IWebViewControlPermissionRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Web::UI::IWebViewControlScriptNotifyEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Web::UI::IWebViewControlSettings>{ using type = interface_category; };
    template <> struct category<llm::OS::Web::UI::IWebViewControlUnsupportedUriSchemeIdentifiedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Web::UI::IWebViewControlUnviewableContentIdentifiedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Web::UI::IWebViewControlWebResourceRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Web::UI::WebViewControlContentLoadingEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Web::UI::WebViewControlDOMContentLoadedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Web::UI::WebViewControlDeferredPermissionRequest>{ using type = class_category; };
    template <> struct category<llm::OS::Web::UI::WebViewControlLongRunningScriptDetectedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Web::UI::WebViewControlNavigationCompletedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Web::UI::WebViewControlNavigationStartingEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Web::UI::WebViewControlNewWindowRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Web::UI::WebViewControlPermissionRequest>{ using type = class_category; };
    template <> struct category<llm::OS::Web::UI::WebViewControlPermissionRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Web::UI::WebViewControlScriptNotifyEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Web::UI::WebViewControlSettings>{ using type = class_category; };
    template <> struct category<llm::OS::Web::UI::WebViewControlUnsupportedUriSchemeIdentifiedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Web::UI::WebViewControlUnviewableContentIdentifiedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Web::UI::WebViewControlWebResourceRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Web::UI::WebViewControlPermissionState>{ using type = enum_category; };
    template <> struct category<llm::OS::Web::UI::WebViewControlPermissionType>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::WebViewControlContentLoadingEventArgs> = L"Windows.Web.UI.WebViewControlContentLoadingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::WebViewControlDOMContentLoadedEventArgs> = L"Windows.Web.UI.WebViewControlDOMContentLoadedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::WebViewControlDeferredPermissionRequest> = L"Windows.Web.UI.WebViewControlDeferredPermissionRequest";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::WebViewControlLongRunningScriptDetectedEventArgs> = L"Windows.Web.UI.WebViewControlLongRunningScriptDetectedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::WebViewControlNavigationCompletedEventArgs> = L"Windows.Web.UI.WebViewControlNavigationCompletedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::WebViewControlNavigationStartingEventArgs> = L"Windows.Web.UI.WebViewControlNavigationStartingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::WebViewControlNewWindowRequestedEventArgs> = L"Windows.Web.UI.WebViewControlNewWindowRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::WebViewControlPermissionRequest> = L"Windows.Web.UI.WebViewControlPermissionRequest";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::WebViewControlPermissionRequestedEventArgs> = L"Windows.Web.UI.WebViewControlPermissionRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::WebViewControlScriptNotifyEventArgs> = L"Windows.Web.UI.WebViewControlScriptNotifyEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::WebViewControlSettings> = L"Windows.Web.UI.WebViewControlSettings";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::WebViewControlUnsupportedUriSchemeIdentifiedEventArgs> = L"Windows.Web.UI.WebViewControlUnsupportedUriSchemeIdentifiedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::WebViewControlUnviewableContentIdentifiedEventArgs> = L"Windows.Web.UI.WebViewControlUnviewableContentIdentifiedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::WebViewControlWebResourceRequestedEventArgs> = L"Windows.Web.UI.WebViewControlWebResourceRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::WebViewControlPermissionState> = L"Windows.Web.UI.WebViewControlPermissionState";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::WebViewControlPermissionType> = L"Windows.Web.UI.WebViewControlPermissionType";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::IWebViewControl> = L"Windows.Web.UI.IWebViewControl";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::IWebViewControl2> = L"Windows.Web.UI.IWebViewControl2";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::IWebViewControlContentLoadingEventArgs> = L"Windows.Web.UI.IWebViewControlContentLoadingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::IWebViewControlDOMContentLoadedEventArgs> = L"Windows.Web.UI.IWebViewControlDOMContentLoadedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::IWebViewControlDeferredPermissionRequest> = L"Windows.Web.UI.IWebViewControlDeferredPermissionRequest";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::IWebViewControlLongRunningScriptDetectedEventArgs> = L"Windows.Web.UI.IWebViewControlLongRunningScriptDetectedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::IWebViewControlNavigationCompletedEventArgs> = L"Windows.Web.UI.IWebViewControlNavigationCompletedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::IWebViewControlNavigationStartingEventArgs> = L"Windows.Web.UI.IWebViewControlNavigationStartingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::IWebViewControlNewWindowRequestedEventArgs> = L"Windows.Web.UI.IWebViewControlNewWindowRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::IWebViewControlNewWindowRequestedEventArgs2> = L"Windows.Web.UI.IWebViewControlNewWindowRequestedEventArgs2";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::IWebViewControlPermissionRequest> = L"Windows.Web.UI.IWebViewControlPermissionRequest";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::IWebViewControlPermissionRequestedEventArgs> = L"Windows.Web.UI.IWebViewControlPermissionRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::IWebViewControlScriptNotifyEventArgs> = L"Windows.Web.UI.IWebViewControlScriptNotifyEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::IWebViewControlSettings> = L"Windows.Web.UI.IWebViewControlSettings";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::IWebViewControlUnsupportedUriSchemeIdentifiedEventArgs> = L"Windows.Web.UI.IWebViewControlUnsupportedUriSchemeIdentifiedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::IWebViewControlUnviewableContentIdentifiedEventArgs> = L"Windows.Web.UI.IWebViewControlUnviewableContentIdentifiedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Web::UI::IWebViewControlWebResourceRequestedEventArgs> = L"Windows.Web.UI.IWebViewControlWebResourceRequestedEventArgs";
    template <> inline constexpr guid guid_v<llm::OS::Web::UI::IWebViewControl>{ 0x3F921316,0xBC70,0x4BDA,{ 0x91,0x36,0xC9,0x43,0x70,0x89,0x9F,0xAB } }; // 3F921316-BC70-4BDA-9136-C94370899FAB
    template <> inline constexpr guid guid_v<llm::OS::Web::UI::IWebViewControl2>{ 0x4D3C06F9,0xC8DF,0x41CC,{ 0x8B,0xD5,0x2A,0x94,0x7B,0x20,0x45,0x03 } }; // 4D3C06F9-C8DF-41CC-8BD5-2A947B204503
    template <> inline constexpr guid guid_v<llm::OS::Web::UI::IWebViewControlContentLoadingEventArgs>{ 0x9A3FCCB2,0xB9BB,0x404B,{ 0xA2,0x2B,0x66,0xDC,0xCD,0x12,0x50,0xC6 } }; // 9A3FCCB2-B9BB-404B-A22B-66DCCD1250C6
    template <> inline constexpr guid guid_v<llm::OS::Web::UI::IWebViewControlDOMContentLoadedEventArgs>{ 0xBE8BC008,0x9541,0x4545,{ 0x9F,0xF2,0x2D,0xF5,0x85,0xB2,0x9F,0x7D } }; // BE8BC008-9541-4545-9FF2-2DF585B29F7D
    template <> inline constexpr guid guid_v<llm::OS::Web::UI::IWebViewControlDeferredPermissionRequest>{ 0x2CE349E0,0xD759,0x445C,{ 0x99,0x26,0x89,0x95,0x29,0x8F,0x15,0x2B } }; // 2CE349E0-D759-445C-9926-8995298F152B
    template <> inline constexpr guid guid_v<llm::OS::Web::UI::IWebViewControlLongRunningScriptDetectedEventArgs>{ 0x2A6E5BBA,0x98B4,0x45BC,{ 0xBB,0xEB,0x0F,0x69,0xCE,0x49,0xC5,0x99 } }; // 2A6E5BBA-98B4-45BC-BBEB-0F69CE49C599
    template <> inline constexpr guid guid_v<llm::OS::Web::UI::IWebViewControlNavigationCompletedEventArgs>{ 0x20409918,0x4A15,0x4C46,{ 0xA5,0x5D,0xF7,0x9E,0xDB,0x0B,0xDE,0x8B } }; // 20409918-4A15-4C46-A55D-F79EDB0BDE8B
    template <> inline constexpr guid guid_v<llm::OS::Web::UI::IWebViewControlNavigationStartingEventArgs>{ 0x0C9057C5,0x0A08,0x41C7,{ 0x86,0x3B,0x71,0xE3,0xA9,0x54,0x91,0x37 } }; // 0C9057C5-0A08-41C7-863B-71E3A9549137
    template <> inline constexpr guid guid_v<llm::OS::Web::UI::IWebViewControlNewWindowRequestedEventArgs>{ 0x3DF44BBB,0xA124,0x46D5,{ 0xA0,0x83,0xD0,0x2C,0xAC,0xDF,0xF5,0xAD } }; // 3DF44BBB-A124-46D5-A083-D02CACDFF5AD
    template <> inline constexpr guid guid_v<llm::OS::Web::UI::IWebViewControlNewWindowRequestedEventArgs2>{ 0xB53C5CA6,0x2AAE,0x4BFC,{ 0x92,0xB9,0xC3,0x0E,0x92,0xB4,0x80,0x98 } }; // B53C5CA6-2AAE-4BFC-92B9-C30E92B48098
    template <> inline constexpr guid guid_v<llm::OS::Web::UI::IWebViewControlPermissionRequest>{ 0xE5BC836C,0xF22F,0x40E2,{ 0x95,0xB2,0x77,0x29,0xF8,0x40,0xEB,0x7F } }; // E5BC836C-F22F-40E2-95B2-7729F840EB7F
    template <> inline constexpr guid guid_v<llm::OS::Web::UI::IWebViewControlPermissionRequestedEventArgs>{ 0x27204D51,0x2488,0x4CC5,{ 0x96,0x8E,0x0A,0x77,0x1E,0x59,0xC1,0x47 } }; // 27204D51-2488-4CC5-968E-0A771E59C147
    template <> inline constexpr guid guid_v<llm::OS::Web::UI::IWebViewControlScriptNotifyEventArgs>{ 0x491DE57B,0x6F49,0x41BB,{ 0xB5,0x91,0x51,0xB8,0x5B,0x81,0x70,0x37 } }; // 491DE57B-6F49-41BB-B591-51B85B817037
    template <> inline constexpr guid guid_v<llm::OS::Web::UI::IWebViewControlSettings>{ 0xC9967FBF,0x5E98,0x4CFD,{ 0x8C,0xCE,0x27,0xB0,0x91,0x1E,0x3D,0xE8 } }; // C9967FBF-5E98-4CFD-8CCE-27B0911E3DE8
    template <> inline constexpr guid guid_v<llm::OS::Web::UI::IWebViewControlUnsupportedUriSchemeIdentifiedEventArgs>{ 0xE3B81944,0xE4FC,0x43DC,{ 0x94,0xCA,0xF9,0x80,0xF3,0x0B,0xC5,0x1D } }; // E3B81944-E4FC-43DC-94CA-F980F30BC51D
    template <> inline constexpr guid guid_v<llm::OS::Web::UI::IWebViewControlUnviewableContentIdentifiedEventArgs>{ 0x4A9680DB,0x88F2,0x4E20,{ 0xB6,0x93,0xB4,0xE2,0xDF,0x4A,0xA5,0x81 } }; // 4A9680DB-88F2-4E20-B693-B4E2DF4AA581
    template <> inline constexpr guid guid_v<llm::OS::Web::UI::IWebViewControlWebResourceRequestedEventArgs>{ 0x44D6524D,0x55A4,0x4D8B,{ 0x89,0x1C,0x93,0x1D,0x8E,0x25,0xD4,0x2E } }; // 44D6524D-55A4-4D8B-891C-931D8E25D42E
    template <> struct default_interface<llm::OS::Web::UI::WebViewControlContentLoadingEventArgs>{ using type = llm::OS::Web::UI::IWebViewControlContentLoadingEventArgs; };
    template <> struct default_interface<llm::OS::Web::UI::WebViewControlDOMContentLoadedEventArgs>{ using type = llm::OS::Web::UI::IWebViewControlDOMContentLoadedEventArgs; };
    template <> struct default_interface<llm::OS::Web::UI::WebViewControlDeferredPermissionRequest>{ using type = llm::OS::Web::UI::IWebViewControlDeferredPermissionRequest; };
    template <> struct default_interface<llm::OS::Web::UI::WebViewControlLongRunningScriptDetectedEventArgs>{ using type = llm::OS::Web::UI::IWebViewControlLongRunningScriptDetectedEventArgs; };
    template <> struct default_interface<llm::OS::Web::UI::WebViewControlNavigationCompletedEventArgs>{ using type = llm::OS::Web::UI::IWebViewControlNavigationCompletedEventArgs; };
    template <> struct default_interface<llm::OS::Web::UI::WebViewControlNavigationStartingEventArgs>{ using type = llm::OS::Web::UI::IWebViewControlNavigationStartingEventArgs; };
    template <> struct default_interface<llm::OS::Web::UI::WebViewControlNewWindowRequestedEventArgs>{ using type = llm::OS::Web::UI::IWebViewControlNewWindowRequestedEventArgs; };
    template <> struct default_interface<llm::OS::Web::UI::WebViewControlPermissionRequest>{ using type = llm::OS::Web::UI::IWebViewControlPermissionRequest; };
    template <> struct default_interface<llm::OS::Web::UI::WebViewControlPermissionRequestedEventArgs>{ using type = llm::OS::Web::UI::IWebViewControlPermissionRequestedEventArgs; };
    template <> struct default_interface<llm::OS::Web::UI::WebViewControlScriptNotifyEventArgs>{ using type = llm::OS::Web::UI::IWebViewControlScriptNotifyEventArgs; };
    template <> struct default_interface<llm::OS::Web::UI::WebViewControlSettings>{ using type = llm::OS::Web::UI::IWebViewControlSettings; };
    template <> struct default_interface<llm::OS::Web::UI::WebViewControlUnsupportedUriSchemeIdentifiedEventArgs>{ using type = llm::OS::Web::UI::IWebViewControlUnsupportedUriSchemeIdentifiedEventArgs; };
    template <> struct default_interface<llm::OS::Web::UI::WebViewControlUnviewableContentIdentifiedEventArgs>{ using type = llm::OS::Web::UI::IWebViewControlUnviewableContentIdentifiedEventArgs; };
    template <> struct default_interface<llm::OS::Web::UI::WebViewControlWebResourceRequestedEventArgs>{ using type = llm::OS::Web::UI::IWebViewControlWebResourceRequestedEventArgs; };
    template <> struct abi<llm::OS::Web::UI::IWebViewControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Source(void**) noexcept = 0;
            virtual int32_t __stdcall put_Source(void*) noexcept = 0;
            virtual int32_t __stdcall get_DocumentTitle(void**) noexcept = 0;
            virtual int32_t __stdcall get_CanGoBack(bool*) noexcept = 0;
            virtual int32_t __stdcall get_CanGoForward(bool*) noexcept = 0;
            virtual int32_t __stdcall put_DefaultBackgroundColor(struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall get_DefaultBackgroundColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall get_ContainsFullScreenElement(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Settings(void**) noexcept = 0;
            virtual int32_t __stdcall get_DeferredPermissionRequests(void**) noexcept = 0;
            virtual int32_t __stdcall GoForward() noexcept = 0;
            virtual int32_t __stdcall GoBack() noexcept = 0;
            virtual int32_t __stdcall Refresh() noexcept = 0;
            virtual int32_t __stdcall Stop() noexcept = 0;
            virtual int32_t __stdcall Navigate(void*) noexcept = 0;
            virtual int32_t __stdcall NavigateToString(void*) noexcept = 0;
            virtual int32_t __stdcall NavigateToLocalStreamUri(void*, void*) noexcept = 0;
            virtual int32_t __stdcall NavigateWithHttpRequestMessage(void*) noexcept = 0;
            virtual int32_t __stdcall InvokeScriptAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CapturePreviewToStreamAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CaptureSelectedContentToDataPackageAsync(void**) noexcept = 0;
            virtual int32_t __stdcall BuildLocalStreamUri(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetDeferredPermissionRequestById(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall add_NavigationStarting(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_NavigationStarting(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ContentLoading(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ContentLoading(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_DOMContentLoaded(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_DOMContentLoaded(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_NavigationCompleted(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_NavigationCompleted(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_FrameNavigationStarting(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_FrameNavigationStarting(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_FrameContentLoading(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_FrameContentLoading(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_FrameDOMContentLoaded(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_FrameDOMContentLoaded(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_FrameNavigationCompleted(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_FrameNavigationCompleted(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ScriptNotify(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ScriptNotify(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_LongRunningScriptDetected(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_LongRunningScriptDetected(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_UnsafeContentWarningDisplaying(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_UnsafeContentWarningDisplaying(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_UnviewableContentIdentified(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_UnviewableContentIdentified(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PermissionRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PermissionRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_UnsupportedUriSchemeIdentified(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_UnsupportedUriSchemeIdentified(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_NewWindowRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_NewWindowRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ContainsFullScreenElementChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ContainsFullScreenElementChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_WebResourceRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_WebResourceRequested(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Web::UI::IWebViewControl2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall AddInitializeScript(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Web::UI::IWebViewControlContentLoadingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Uri(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Web::UI::IWebViewControlDOMContentLoadedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Uri(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Web::UI::IWebViewControlDeferredPermissionRequest>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Uri(void**) noexcept = 0;
            virtual int32_t __stdcall get_PermissionType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall Allow() noexcept = 0;
            virtual int32_t __stdcall Deny() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Web::UI::IWebViewControlLongRunningScriptDetectedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ExecutionTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_StopPageScriptExecution(bool*) noexcept = 0;
            virtual int32_t __stdcall put_StopPageScriptExecution(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Web::UI::IWebViewControlNavigationCompletedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Uri(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsSuccess(bool*) noexcept = 0;
            virtual int32_t __stdcall get_WebErrorStatus(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Web::UI::IWebViewControlNavigationStartingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Uri(void**) noexcept = 0;
            virtual int32_t __stdcall get_Cancel(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Cancel(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Web::UI::IWebViewControlNewWindowRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Uri(void**) noexcept = 0;
            virtual int32_t __stdcall get_Referrer(void**) noexcept = 0;
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Web::UI::IWebViewControlNewWindowRequestedEventArgs2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_NewWindow(void**) noexcept = 0;
            virtual int32_t __stdcall put_NewWindow(void*) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Web::UI::IWebViewControlPermissionRequest>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Uri(void**) noexcept = 0;
            virtual int32_t __stdcall get_PermissionType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_State(int32_t*) noexcept = 0;
            virtual int32_t __stdcall Defer() noexcept = 0;
            virtual int32_t __stdcall Allow() noexcept = 0;
            virtual int32_t __stdcall Deny() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Web::UI::IWebViewControlPermissionRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PermissionRequest(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Web::UI::IWebViewControlScriptNotifyEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Uri(void**) noexcept = 0;
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Web::UI::IWebViewControlSettings>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall put_IsJavaScriptEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsJavaScriptEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsIndexedDBEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsIndexedDBEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsScriptNotifyAllowed(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsScriptNotifyAllowed(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Web::UI::IWebViewControlUnsupportedUriSchemeIdentifiedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Uri(void**) noexcept = 0;
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Web::UI::IWebViewControlUnviewableContentIdentifiedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Uri(void**) noexcept = 0;
            virtual int32_t __stdcall get_Referrer(void**) noexcept = 0;
            virtual int32_t __stdcall get_MediaType(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Web::UI::IWebViewControlWebResourceRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
            virtual int32_t __stdcall get_Request(void**) noexcept = 0;
            virtual int32_t __stdcall put_Response(void*) noexcept = 0;
            virtual int32_t __stdcall get_Response(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Web_UI_IWebViewControl
    {
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Foundation::Uri) Source() const;
        WINRT_IMPL_AUTO(void) Source(llm::OS::Foundation::Uri const& source) const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) DocumentTitle() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) CanGoBack() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) CanGoForward() const;
        WINRT_IMPL_AUTO(void) DefaultBackgroundColor(llm::OS::UI::Color const& value) const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::UI::Color) DefaultBackgroundColor() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) ContainsFullScreenElement() const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Web::UI::WebViewControlSettings) Settings() const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Web::UI::WebViewControlDeferredPermissionRequest>) DeferredPermissionRequests() const;
        WINRT_IMPL_AUTO(void) GoForward() const;
        WINRT_IMPL_AUTO(void) GoBack() const;
        WINRT_IMPL_AUTO(void) Refresh() const;
        WINRT_IMPL_AUTO(void) Stop() const;
        WINRT_IMPL_AUTO(void) Navigate(llm::OS::Foundation::Uri const& source) const;
        WINRT_IMPL_AUTO(void) NavigateToString(param::hstring const& text) const;
        WINRT_IMPL_AUTO(void) NavigateToLocalStreamUri(llm::OS::Foundation::Uri const& source, llm::OS::Web::IUriToStreamResolver const& streamResolver) const;
        WINRT_IMPL_AUTO(void) NavigateWithHttpRequestMessage(llm::OS::Web::Http::HttpRequestMessage const& requestMessage) const;
        WINRT_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) InvokeScriptAsync(param::hstring const& scriptName, param::async_iterable<hstring> const& arguments) const;
        WINRT_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) CapturePreviewToStreamAsync(llm::OS::Storage::Streams::IRandomAccessStream const& stream) const;
        WINRT_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::DataTransfer::DataPackage>) CaptureSelectedContentToDataPackageAsync() const;
        WINRT_IMPL_AUTO(llm::OS::Foundation::Uri) BuildLocalStreamUri(param::hstring const& contentIdentifier, param::hstring const& relativePath) const;
        WINRT_IMPL_AUTO(void) GetDeferredPermissionRequestById(uint32_t id, llm::OS::Web::UI::WebViewControlDeferredPermissionRequest& result) const;
        WINRT_IMPL_AUTO(llm::event_token) NavigationStarting(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlNavigationStartingEventArgs> const& handler) const;
        using NavigationStarting_revoker = impl::event_revoker<llm::OS::Web::UI::IWebViewControl, &impl::abi_t<llm::OS::Web::UI::IWebViewControl>::remove_NavigationStarting>;
        [[nodiscard]] NavigationStarting_revoker NavigationStarting(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlNavigationStartingEventArgs> const& handler) const;
        WINRT_IMPL_AUTO(void) NavigationStarting(llm::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(llm::event_token) ContentLoading(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlContentLoadingEventArgs> const& handler) const;
        using ContentLoading_revoker = impl::event_revoker<llm::OS::Web::UI::IWebViewControl, &impl::abi_t<llm::OS::Web::UI::IWebViewControl>::remove_ContentLoading>;
        [[nodiscard]] ContentLoading_revoker ContentLoading(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlContentLoadingEventArgs> const& handler) const;
        WINRT_IMPL_AUTO(void) ContentLoading(llm::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(llm::event_token) DOMContentLoaded(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlDOMContentLoadedEventArgs> const& handler) const;
        using DOMContentLoaded_revoker = impl::event_revoker<llm::OS::Web::UI::IWebViewControl, &impl::abi_t<llm::OS::Web::UI::IWebViewControl>::remove_DOMContentLoaded>;
        [[nodiscard]] DOMContentLoaded_revoker DOMContentLoaded(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlDOMContentLoadedEventArgs> const& handler) const;
        WINRT_IMPL_AUTO(void) DOMContentLoaded(llm::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(llm::event_token) NavigationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlNavigationCompletedEventArgs> const& handler) const;
        using NavigationCompleted_revoker = impl::event_revoker<llm::OS::Web::UI::IWebViewControl, &impl::abi_t<llm::OS::Web::UI::IWebViewControl>::remove_NavigationCompleted>;
        [[nodiscard]] NavigationCompleted_revoker NavigationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlNavigationCompletedEventArgs> const& handler) const;
        WINRT_IMPL_AUTO(void) NavigationCompleted(llm::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(llm::event_token) FrameNavigationStarting(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlNavigationStartingEventArgs> const& handler) const;
        using FrameNavigationStarting_revoker = impl::event_revoker<llm::OS::Web::UI::IWebViewControl, &impl::abi_t<llm::OS::Web::UI::IWebViewControl>::remove_FrameNavigationStarting>;
        [[nodiscard]] FrameNavigationStarting_revoker FrameNavigationStarting(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlNavigationStartingEventArgs> const& handler) const;
        WINRT_IMPL_AUTO(void) FrameNavigationStarting(llm::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(llm::event_token) FrameContentLoading(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlContentLoadingEventArgs> const& handler) const;
        using FrameContentLoading_revoker = impl::event_revoker<llm::OS::Web::UI::IWebViewControl, &impl::abi_t<llm::OS::Web::UI::IWebViewControl>::remove_FrameContentLoading>;
        [[nodiscard]] FrameContentLoading_revoker FrameContentLoading(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlContentLoadingEventArgs> const& handler) const;
        WINRT_IMPL_AUTO(void) FrameContentLoading(llm::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(llm::event_token) FrameDOMContentLoaded(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlDOMContentLoadedEventArgs> const& handler) const;
        using FrameDOMContentLoaded_revoker = impl::event_revoker<llm::OS::Web::UI::IWebViewControl, &impl::abi_t<llm::OS::Web::UI::IWebViewControl>::remove_FrameDOMContentLoaded>;
        [[nodiscard]] FrameDOMContentLoaded_revoker FrameDOMContentLoaded(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlDOMContentLoadedEventArgs> const& handler) const;
        WINRT_IMPL_AUTO(void) FrameDOMContentLoaded(llm::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(llm::event_token) FrameNavigationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlNavigationCompletedEventArgs> const& handler) const;
        using FrameNavigationCompleted_revoker = impl::event_revoker<llm::OS::Web::UI::IWebViewControl, &impl::abi_t<llm::OS::Web::UI::IWebViewControl>::remove_FrameNavigationCompleted>;
        [[nodiscard]] FrameNavigationCompleted_revoker FrameNavigationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlNavigationCompletedEventArgs> const& handler) const;
        WINRT_IMPL_AUTO(void) FrameNavigationCompleted(llm::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(llm::event_token) ScriptNotify(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlScriptNotifyEventArgs> const& handler) const;
        using ScriptNotify_revoker = impl::event_revoker<llm::OS::Web::UI::IWebViewControl, &impl::abi_t<llm::OS::Web::UI::IWebViewControl>::remove_ScriptNotify>;
        [[nodiscard]] ScriptNotify_revoker ScriptNotify(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlScriptNotifyEventArgs> const& handler) const;
        WINRT_IMPL_AUTO(void) ScriptNotify(llm::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(llm::event_token) LongRunningScriptDetected(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlLongRunningScriptDetectedEventArgs> const& handler) const;
        using LongRunningScriptDetected_revoker = impl::event_revoker<llm::OS::Web::UI::IWebViewControl, &impl::abi_t<llm::OS::Web::UI::IWebViewControl>::remove_LongRunningScriptDetected>;
        [[nodiscard]] LongRunningScriptDetected_revoker LongRunningScriptDetected(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlLongRunningScriptDetectedEventArgs> const& handler) const;
        WINRT_IMPL_AUTO(void) LongRunningScriptDetected(llm::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(llm::event_token) UnsafeContentWarningDisplaying(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Foundation::IInspectable> const& handler) const;
        using UnsafeContentWarningDisplaying_revoker = impl::event_revoker<llm::OS::Web::UI::IWebViewControl, &impl::abi_t<llm::OS::Web::UI::IWebViewControl>::remove_UnsafeContentWarningDisplaying>;
        [[nodiscard]] UnsafeContentWarningDisplaying_revoker UnsafeContentWarningDisplaying(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Foundation::IInspectable> const& handler) const;
        WINRT_IMPL_AUTO(void) UnsafeContentWarningDisplaying(llm::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(llm::event_token) UnviewableContentIdentified(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlUnviewableContentIdentifiedEventArgs> const& handler) const;
        using UnviewableContentIdentified_revoker = impl::event_revoker<llm::OS::Web::UI::IWebViewControl, &impl::abi_t<llm::OS::Web::UI::IWebViewControl>::remove_UnviewableContentIdentified>;
        [[nodiscard]] UnviewableContentIdentified_revoker UnviewableContentIdentified(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlUnviewableContentIdentifiedEventArgs> const& handler) const;
        WINRT_IMPL_AUTO(void) UnviewableContentIdentified(llm::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(llm::event_token) PermissionRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlPermissionRequestedEventArgs> const& handler) const;
        using PermissionRequested_revoker = impl::event_revoker<llm::OS::Web::UI::IWebViewControl, &impl::abi_t<llm::OS::Web::UI::IWebViewControl>::remove_PermissionRequested>;
        [[nodiscard]] PermissionRequested_revoker PermissionRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlPermissionRequestedEventArgs> const& handler) const;
        WINRT_IMPL_AUTO(void) PermissionRequested(llm::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(llm::event_token) UnsupportedUriSchemeIdentified(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlUnsupportedUriSchemeIdentifiedEventArgs> const& handler) const;
        using UnsupportedUriSchemeIdentified_revoker = impl::event_revoker<llm::OS::Web::UI::IWebViewControl, &impl::abi_t<llm::OS::Web::UI::IWebViewControl>::remove_UnsupportedUriSchemeIdentified>;
        [[nodiscard]] UnsupportedUriSchemeIdentified_revoker UnsupportedUriSchemeIdentified(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlUnsupportedUriSchemeIdentifiedEventArgs> const& handler) const;
        WINRT_IMPL_AUTO(void) UnsupportedUriSchemeIdentified(llm::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(llm::event_token) NewWindowRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlNewWindowRequestedEventArgs> const& handler) const;
        using NewWindowRequested_revoker = impl::event_revoker<llm::OS::Web::UI::IWebViewControl, &impl::abi_t<llm::OS::Web::UI::IWebViewControl>::remove_NewWindowRequested>;
        [[nodiscard]] NewWindowRequested_revoker NewWindowRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlNewWindowRequestedEventArgs> const& handler) const;
        WINRT_IMPL_AUTO(void) NewWindowRequested(llm::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(llm::event_token) ContainsFullScreenElementChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Foundation::IInspectable> const& handler) const;
        using ContainsFullScreenElementChanged_revoker = impl::event_revoker<llm::OS::Web::UI::IWebViewControl, &impl::abi_t<llm::OS::Web::UI::IWebViewControl>::remove_ContainsFullScreenElementChanged>;
        [[nodiscard]] ContainsFullScreenElementChanged_revoker ContainsFullScreenElementChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Foundation::IInspectable> const& handler) const;
        WINRT_IMPL_AUTO(void) ContainsFullScreenElementChanged(llm::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(llm::event_token) WebResourceRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlWebResourceRequestedEventArgs> const& handler) const;
        using WebResourceRequested_revoker = impl::event_revoker<llm::OS::Web::UI::IWebViewControl, &impl::abi_t<llm::OS::Web::UI::IWebViewControl>::remove_WebResourceRequested>;
        [[nodiscard]] WebResourceRequested_revoker WebResourceRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::UI::IWebViewControl, llm::OS::Web::UI::WebViewControlWebResourceRequestedEventArgs> const& handler) const;
        WINRT_IMPL_AUTO(void) WebResourceRequested(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::Web::UI::IWebViewControl>
    {
        template <typename D> using type = consume_Windows_Web_UI_IWebViewControl<D>;
    };
    template <typename D>
    struct consume_Windows_Web_UI_IWebViewControl2
    {
        WINRT_IMPL_AUTO(void) AddInitializeScript(param::hstring const& script) const;
    };
    template <> struct consume<llm::OS::Web::UI::IWebViewControl2>
    {
        template <typename D> using type = consume_Windows_Web_UI_IWebViewControl2<D>;
    };
    template <typename D>
    struct consume_Windows_Web_UI_IWebViewControlContentLoadingEventArgs
    {
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Foundation::Uri) Uri() const;
    };
    template <> struct consume<llm::OS::Web::UI::IWebViewControlContentLoadingEventArgs>
    {
        template <typename D> using type = consume_Windows_Web_UI_IWebViewControlContentLoadingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Web_UI_IWebViewControlDOMContentLoadedEventArgs
    {
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Foundation::Uri) Uri() const;
    };
    template <> struct consume<llm::OS::Web::UI::IWebViewControlDOMContentLoadedEventArgs>
    {
        template <typename D> using type = consume_Windows_Web_UI_IWebViewControlDOMContentLoadedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Web_UI_IWebViewControlDeferredPermissionRequest
    {
        [[nodiscard]] WINRT_IMPL_AUTO(uint32_t) Id() const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Foundation::Uri) Uri() const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Web::UI::WebViewControlPermissionType) PermissionType() const;
        WINRT_IMPL_AUTO(void) Allow() const;
        WINRT_IMPL_AUTO(void) Deny() const;
    };
    template <> struct consume<llm::OS::Web::UI::IWebViewControlDeferredPermissionRequest>
    {
        template <typename D> using type = consume_Windows_Web_UI_IWebViewControlDeferredPermissionRequest<D>;
    };
    template <typename D>
    struct consume_Windows_Web_UI_IWebViewControlLongRunningScriptDetectedEventArgs
    {
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Foundation::TimeSpan) ExecutionTime() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) StopPageScriptExecution() const;
        WINRT_IMPL_AUTO(void) StopPageScriptExecution(bool value) const;
    };
    template <> struct consume<llm::OS::Web::UI::IWebViewControlLongRunningScriptDetectedEventArgs>
    {
        template <typename D> using type = consume_Windows_Web_UI_IWebViewControlLongRunningScriptDetectedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Web_UI_IWebViewControlNavigationCompletedEventArgs
    {
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Foundation::Uri) Uri() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsSuccess() const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Web::WebErrorStatus) WebErrorStatus() const;
    };
    template <> struct consume<llm::OS::Web::UI::IWebViewControlNavigationCompletedEventArgs>
    {
        template <typename D> using type = consume_Windows_Web_UI_IWebViewControlNavigationCompletedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Web_UI_IWebViewControlNavigationStartingEventArgs
    {
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Foundation::Uri) Uri() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) Cancel() const;
        WINRT_IMPL_AUTO(void) Cancel(bool value) const;
    };
    template <> struct consume<llm::OS::Web::UI::IWebViewControlNavigationStartingEventArgs>
    {
        template <typename D> using type = consume_Windows_Web_UI_IWebViewControlNavigationStartingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Web_UI_IWebViewControlNewWindowRequestedEventArgs
    {
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Foundation::Uri) Uri() const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Foundation::Uri) Referrer() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) Handled() const;
        WINRT_IMPL_AUTO(void) Handled(bool value) const;
    };
    template <> struct consume<llm::OS::Web::UI::IWebViewControlNewWindowRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_Web_UI_IWebViewControlNewWindowRequestedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Web_UI_IWebViewControlNewWindowRequestedEventArgs2
    {
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Web::UI::IWebViewControl) NewWindow() const;
        WINRT_IMPL_AUTO(void) NewWindow(llm::OS::Web::UI::IWebViewControl const& value) const;
        WINRT_IMPL_AUTO(llm::OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm::OS::Web::UI::IWebViewControlNewWindowRequestedEventArgs2>
    {
        template <typename D> using type = consume_Windows_Web_UI_IWebViewControlNewWindowRequestedEventArgs2<D>;
    };
    template <typename D>
    struct consume_Windows_Web_UI_IWebViewControlPermissionRequest
    {
        [[nodiscard]] WINRT_IMPL_AUTO(uint32_t) Id() const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Foundation::Uri) Uri() const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Web::UI::WebViewControlPermissionType) PermissionType() const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Web::UI::WebViewControlPermissionState) State() const;
        WINRT_IMPL_AUTO(void) Defer() const;
        WINRT_IMPL_AUTO(void) Allow() const;
        WINRT_IMPL_AUTO(void) Deny() const;
    };
    template <> struct consume<llm::OS::Web::UI::IWebViewControlPermissionRequest>
    {
        template <typename D> using type = consume_Windows_Web_UI_IWebViewControlPermissionRequest<D>;
    };
    template <typename D>
    struct consume_Windows_Web_UI_IWebViewControlPermissionRequestedEventArgs
    {
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Web::UI::WebViewControlPermissionRequest) PermissionRequest() const;
    };
    template <> struct consume<llm::OS::Web::UI::IWebViewControlPermissionRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_Web_UI_IWebViewControlPermissionRequestedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Web_UI_IWebViewControlScriptNotifyEventArgs
    {
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Foundation::Uri) Uri() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Value() const;
    };
    template <> struct consume<llm::OS::Web::UI::IWebViewControlScriptNotifyEventArgs>
    {
        template <typename D> using type = consume_Windows_Web_UI_IWebViewControlScriptNotifyEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Web_UI_IWebViewControlSettings
    {
        WINRT_IMPL_AUTO(void) IsJavaScriptEnabled(bool value) const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsJavaScriptEnabled() const;
        WINRT_IMPL_AUTO(void) IsIndexedDBEnabled(bool value) const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsIndexedDBEnabled() const;
        WINRT_IMPL_AUTO(void) IsScriptNotifyAllowed(bool value) const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsScriptNotifyAllowed() const;
    };
    template <> struct consume<llm::OS::Web::UI::IWebViewControlSettings>
    {
        template <typename D> using type = consume_Windows_Web_UI_IWebViewControlSettings<D>;
    };
    template <typename D>
    struct consume_Windows_Web_UI_IWebViewControlUnsupportedUriSchemeIdentifiedEventArgs
    {
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Foundation::Uri) Uri() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) Handled() const;
        WINRT_IMPL_AUTO(void) Handled(bool value) const;
    };
    template <> struct consume<llm::OS::Web::UI::IWebViewControlUnsupportedUriSchemeIdentifiedEventArgs>
    {
        template <typename D> using type = consume_Windows_Web_UI_IWebViewControlUnsupportedUriSchemeIdentifiedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Web_UI_IWebViewControlUnviewableContentIdentifiedEventArgs
    {
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Foundation::Uri) Uri() const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Foundation::Uri) Referrer() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) MediaType() const;
    };
    template <> struct consume<llm::OS::Web::UI::IWebViewControlUnviewableContentIdentifiedEventArgs>
    {
        template <typename D> using type = consume_Windows_Web_UI_IWebViewControlUnviewableContentIdentifiedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Web_UI_IWebViewControlWebResourceRequestedEventArgs
    {
        WINRT_IMPL_AUTO(llm::OS::Foundation::Deferral) GetDeferral() const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Web::Http::HttpRequestMessage) Request() const;
        WINRT_IMPL_AUTO(void) Response(llm::OS::Web::Http::HttpResponseMessage const& value) const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::Web::Http::HttpResponseMessage) Response() const;
    };
    template <> struct consume<llm::OS::Web::UI::IWebViewControlWebResourceRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_Web_UI_IWebViewControlWebResourceRequestedEventArgs<D>;
    };
}
#endif
