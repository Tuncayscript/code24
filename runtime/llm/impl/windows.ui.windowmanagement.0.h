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
#ifndef LLM_OS_UI_WindowManagement_0_H
#define LLM_OS_UI_WindowManagement_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct Deferral;
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    struct Point;
    struct Rect;
    struct Size;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm::OS::System
{
    struct DispatcherQueue;
}
LLM_EXPORT namespace llm::OS::UI
{
    struct Color;
    struct UIContentRoot;
    struct UIContext;
    struct WindowId;
}
LLM_EXPORT namespace llm::OS::UI::Composition
{
    struct IVisualElement;
}
LLM_EXPORT namespace llm::OS::UI::WindowManagement
{
    enum class AppWindowClosedReason : int32_t
    {
        Other = 0,
        AppInitiated = 1,
        UserInitiated = 2,
    };
    enum class AppWindowFrameStyle : int32_t
    {
        Default = 0,
        NoFrame = 1,
    };
    enum class AppWindowPresentationKind : int32_t
    {
        Default = 0,
        CompactOverlay = 1,
        FullScreen = 2,
    };
    enum class AppWindowTitleBarVisibility : int32_t
    {
        Default = 0,
        AlwaysHidden = 1,
    };
    enum class WindowingEnvironmentKind : int32_t
    {
        Unknown = 0,
        Overlapped = 1,
        Tiled = 2,
    };
    struct IAppWindow;
    struct IAppWindowChangedEventArgs;
    struct IAppWindowCloseRequestedEventArgs;
    struct IAppWindowClosedEventArgs;
    struct IAppWindowFrame;
    struct IAppWindowFrameStyle;
    struct IAppWindowPlacement;
    struct IAppWindowPresentationConfiguration;
    struct IAppWindowPresentationConfigurationFactory;
    struct IAppWindowPresenter;
    struct IAppWindowStatics;
    struct IAppWindowTitleBar;
    struct IAppWindowTitleBarOcclusion;
    struct IAppWindowTitleBarVisibility;
    struct ICompactOverlayPresentationConfiguration;
    struct IDefaultPresentationConfiguration;
    struct IDisplayRegion;
    struct IFullScreenPresentationConfiguration;
    struct IWindowServicesStatics;
    struct IWindowingEnvironment;
    struct IWindowingEnvironmentAddedEventArgs;
    struct IWindowingEnvironmentChangedEventArgs;
    struct IWindowingEnvironmentRemovedEventArgs;
    struct IWindowingEnvironmentStatics;
    struct AppWindow;
    struct AppWindowChangedEventArgs;
    struct AppWindowCloseRequestedEventArgs;
    struct AppWindowClosedEventArgs;
    struct AppWindowFrame;
    struct AppWindowPlacement;
    struct AppWindowPresentationConfiguration;
    struct AppWindowPresenter;
    struct AppWindowTitleBar;
    struct AppWindowTitleBarOcclusion;
    struct CompactOverlayPresentationConfiguration;
    struct DefaultPresentationConfiguration;
    struct DisplayRegion;
    struct FullScreenPresentationConfiguration;
    struct WindowServices;
    struct WindowingEnvironment;
    struct WindowingEnvironmentAddedEventArgs;
    struct WindowingEnvironmentChangedEventArgs;
    struct WindowingEnvironmentRemovedEventArgs;
}
namespace llm::impl
{
    template <> struct category<llm::OS::UI::WindowManagement::IAppWindow>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IAppWindowCloseRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IAppWindowClosedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IAppWindowFrame>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IAppWindowFrameStyle>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IAppWindowPlacement>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IAppWindowPresentationConfiguration>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IAppWindowPresentationConfigurationFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IAppWindowPresenter>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IAppWindowStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IAppWindowTitleBar>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IAppWindowTitleBarOcclusion>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IAppWindowTitleBarVisibility>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::ICompactOverlayPresentationConfiguration>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IDefaultPresentationConfiguration>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IDisplayRegion>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IFullScreenPresentationConfiguration>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IWindowServicesStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IWindowingEnvironment>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IWindowingEnvironmentAddedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IWindowingEnvironmentChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IWindowingEnvironmentRemovedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::IWindowingEnvironmentStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::AppWindow>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::AppWindowChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::AppWindowCloseRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::AppWindowClosedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::AppWindowFrame>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::AppWindowPlacement>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::AppWindowPresentationConfiguration>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::AppWindowPresenter>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::AppWindowTitleBar>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::AppWindowTitleBarOcclusion>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::CompactOverlayPresentationConfiguration>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::DefaultPresentationConfiguration>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::DisplayRegion>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::FullScreenPresentationConfiguration>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::WindowServices>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::WindowingEnvironment>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::WindowingEnvironmentAddedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::WindowingEnvironmentChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::WindowingEnvironmentRemovedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::WindowManagement::AppWindowClosedReason>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::WindowManagement::AppWindowFrameStyle>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::WindowManagement::AppWindowPresentationKind>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::WindowManagement::AppWindowTitleBarVisibility>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::WindowManagement::WindowingEnvironmentKind>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::AppWindow> = L"Windows.UI.WindowManagement.AppWindow";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::AppWindowChangedEventArgs> = L"Windows.UI.WindowManagement.AppWindowChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::AppWindowCloseRequestedEventArgs> = L"Windows.UI.WindowManagement.AppWindowCloseRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::AppWindowClosedEventArgs> = L"Windows.UI.WindowManagement.AppWindowClosedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::AppWindowFrame> = L"Windows.UI.WindowManagement.AppWindowFrame";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::AppWindowPlacement> = L"Windows.UI.WindowManagement.AppWindowPlacement";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::AppWindowPresentationConfiguration> = L"Windows.UI.WindowManagement.AppWindowPresentationConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::AppWindowPresenter> = L"Windows.UI.WindowManagement.AppWindowPresenter";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::AppWindowTitleBar> = L"Windows.UI.WindowManagement.AppWindowTitleBar";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::AppWindowTitleBarOcclusion> = L"Windows.UI.WindowManagement.AppWindowTitleBarOcclusion";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::CompactOverlayPresentationConfiguration> = L"Windows.UI.WindowManagement.CompactOverlayPresentationConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::DefaultPresentationConfiguration> = L"Windows.UI.WindowManagement.DefaultPresentationConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::DisplayRegion> = L"Windows.UI.WindowManagement.DisplayRegion";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::FullScreenPresentationConfiguration> = L"Windows.UI.WindowManagement.FullScreenPresentationConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::WindowServices> = L"Windows.UI.WindowManagement.WindowServices";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::WindowingEnvironment> = L"Windows.UI.WindowManagement.WindowingEnvironment";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::WindowingEnvironmentAddedEventArgs> = L"Windows.UI.WindowManagement.WindowingEnvironmentAddedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::WindowingEnvironmentChangedEventArgs> = L"Windows.UI.WindowManagement.WindowingEnvironmentChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::WindowingEnvironmentRemovedEventArgs> = L"Windows.UI.WindowManagement.WindowingEnvironmentRemovedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::AppWindowClosedReason> = L"Windows.UI.WindowManagement.AppWindowClosedReason";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::AppWindowFrameStyle> = L"Windows.UI.WindowManagement.AppWindowFrameStyle";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::AppWindowPresentationKind> = L"Windows.UI.WindowManagement.AppWindowPresentationKind";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::AppWindowTitleBarVisibility> = L"Windows.UI.WindowManagement.AppWindowTitleBarVisibility";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::WindowingEnvironmentKind> = L"Windows.UI.WindowManagement.WindowingEnvironmentKind";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IAppWindow> = L"Windows.UI.WindowManagement.IAppWindow";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs> = L"Windows.UI.WindowManagement.IAppWindowChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IAppWindowCloseRequestedEventArgs> = L"Windows.UI.WindowManagement.IAppWindowCloseRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IAppWindowClosedEventArgs> = L"Windows.UI.WindowManagement.IAppWindowClosedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IAppWindowFrame> = L"Windows.UI.WindowManagement.IAppWindowFrame";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IAppWindowFrameStyle> = L"Windows.UI.WindowManagement.IAppWindowFrameStyle";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IAppWindowPlacement> = L"Windows.UI.WindowManagement.IAppWindowPlacement";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IAppWindowPresentationConfiguration> = L"Windows.UI.WindowManagement.IAppWindowPresentationConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IAppWindowPresentationConfigurationFactory> = L"Windows.UI.WindowManagement.IAppWindowPresentationConfigurationFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IAppWindowPresenter> = L"Windows.UI.WindowManagement.IAppWindowPresenter";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IAppWindowStatics> = L"Windows.UI.WindowManagement.IAppWindowStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IAppWindowTitleBar> = L"Windows.UI.WindowManagement.IAppWindowTitleBar";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IAppWindowTitleBarOcclusion> = L"Windows.UI.WindowManagement.IAppWindowTitleBarOcclusion";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IAppWindowTitleBarVisibility> = L"Windows.UI.WindowManagement.IAppWindowTitleBarVisibility";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::ICompactOverlayPresentationConfiguration> = L"Windows.UI.WindowManagement.ICompactOverlayPresentationConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IDefaultPresentationConfiguration> = L"Windows.UI.WindowManagement.IDefaultPresentationConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IDisplayRegion> = L"Windows.UI.WindowManagement.IDisplayRegion";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IFullScreenPresentationConfiguration> = L"Windows.UI.WindowManagement.IFullScreenPresentationConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IWindowServicesStatics> = L"Windows.UI.WindowManagement.IWindowServicesStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IWindowingEnvironment> = L"Windows.UI.WindowManagement.IWindowingEnvironment";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IWindowingEnvironmentAddedEventArgs> = L"Windows.UI.WindowManagement.IWindowingEnvironmentAddedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IWindowingEnvironmentChangedEventArgs> = L"Windows.UI.WindowManagement.IWindowingEnvironmentChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IWindowingEnvironmentRemovedEventArgs> = L"Windows.UI.WindowManagement.IWindowingEnvironmentRemovedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::IWindowingEnvironmentStatics> = L"Windows.UI.WindowManagement.IWindowingEnvironmentStatics";
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IAppWindow>{ 0x663014A6,0xB75E,0x5DBD,{ 0x99,0x5C,0xF0,0x11,0x7F,0xA3,0xFB,0x61 } }; // 663014A6-B75E-5DBD-995C-F0117FA3FB61
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs>{ 0x1DE1F3BE,0xA655,0x55AD,{ 0xB2,0xB6,0xEB,0x24,0x0F,0x88,0x03,0x56 } }; // 1DE1F3BE-A655-55AD-B2B6-EB240F880356
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IAppWindowCloseRequestedEventArgs>{ 0xE9FF01DA,0xE7A2,0x57A8,{ 0x8B,0x5E,0x39,0xC4,0x00,0x3A,0xFD,0xBB } }; // E9FF01DA-E7A2-57A8-8B5E-39C4003AFDBB
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IAppWindowClosedEventArgs>{ 0xCC7DF816,0x9520,0x5A06,{ 0x82,0x1E,0x45,0x6A,0xD8,0xB3,0x58,0xAA } }; // CC7DF816-9520-5A06-821E-456AD8B358AA
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IAppWindowFrame>{ 0x9EE22601,0x7E5D,0x52AF,{ 0x84,0x6B,0x01,0xDC,0x6C,0x29,0x65,0x67 } }; // 9EE22601-7E5D-52AF-846B-01DC6C296567
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IAppWindowFrameStyle>{ 0xAC412946,0xE1AC,0x5230,{ 0x94,0x4A,0xC6,0x08,0x73,0xDC,0xF4,0xA9 } }; // AC412946-E1AC-5230-944A-C60873DCF4A9
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IAppWindowPlacement>{ 0x03DC815E,0xE7A9,0x5857,{ 0x9C,0x03,0x7D,0x67,0x05,0x94,0x41,0x0E } }; // 03DC815E-E7A9-5857-9C03-7D670594410E
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IAppWindowPresentationConfiguration>{ 0xB5A43EE3,0xDF33,0x5E67,{ 0xBD,0x31,0x10,0x72,0x45,0x73,0x00,0xDF } }; // B5A43EE3-DF33-5E67-BD31-1072457300DF
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IAppWindowPresentationConfigurationFactory>{ 0xFD3606A6,0x7875,0x5DE8,{ 0x84,0xFF,0x63,0x51,0xEE,0x13,0xDD,0x0D } }; // FD3606A6-7875-5DE8-84FF-6351EE13DD0D
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IAppWindowPresenter>{ 0x5AE9ED73,0xE1FD,0x5317,{ 0xAD,0x78,0x5A,0x3E,0xD2,0x71,0xBB,0xDE } }; // 5AE9ED73-E1FD-5317-AD78-5A3ED271BBDE
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IAppWindowStatics>{ 0xFF1F3EA3,0xB769,0x50EF,{ 0x98,0x73,0x10,0x8C,0xD0,0xE8,0x97,0x46 } }; // FF1F3EA3-B769-50EF-9873-108CD0E89746
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IAppWindowTitleBar>{ 0x6E932C84,0xF644,0x541D,{ 0xA2,0xD7,0x0C,0x26,0x24,0x37,0x84,0x2D } }; // 6E932C84-F644-541D-A2D7-0C262437842D
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IAppWindowTitleBarOcclusion>{ 0xFEA3CFFD,0x2CCF,0x5FC3,{ 0xAE,0xAE,0xF8,0x43,0x87,0x6B,0xF3,0x7E } }; // FEA3CFFD-2CCF-5FC3-AEAE-F843876BF37E
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IAppWindowTitleBarVisibility>{ 0xA215A4E3,0x6E7E,0x5651,{ 0x8C,0x3B,0x62,0x48,0x19,0x52,0x81,0x54 } }; // A215A4E3-6E7E-5651-8C3B-624819528154
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::ICompactOverlayPresentationConfiguration>{ 0xA7E5750F,0x5730,0x56C6,{ 0x8E,0x1F,0xD6,0x3F,0xF4,0xD7,0x98,0x0D } }; // A7E5750F-5730-56C6-8E1F-D63FF4D7980D
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IDefaultPresentationConfiguration>{ 0xD8C2B53B,0x2168,0x5703,{ 0xA8,0x53,0xD5,0x25,0x58,0x9F,0xE2,0xB9 } }; // D8C2B53B-2168-5703-A853-D525589FE2B9
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IDisplayRegion>{ 0xDB50C3A2,0x4094,0x5F47,{ 0x8C,0xB1,0xEA,0x01,0xDD,0xAF,0xAA,0x94 } }; // DB50C3A2-4094-5F47-8CB1-EA01DDAFAA94
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IFullScreenPresentationConfiguration>{ 0x43D3DCD8,0xD2A8,0x503D,{ 0xA6,0x26,0x15,0x53,0x3D,0x6D,0x5F,0x62 } }; // 43D3DCD8-D2A8-503D-A626-15533D6D5F62
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IWindowServicesStatics>{ 0xCFF4D519,0x50A6,0x5C64,{ 0x97,0xF6,0xC2,0xD9,0x6A,0xDD,0x7F,0x42 } }; // CFF4D519-50A6-5C64-97F6-C2D96ADD7F42
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IWindowingEnvironment>{ 0x264363C0,0x2A49,0x5417,{ 0xB3,0xAE,0x48,0xA7,0x1C,0x63,0xA3,0xBD } }; // 264363C0-2A49-5417-B3AE-48A71C63A3BD
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IWindowingEnvironmentAddedEventArgs>{ 0xFF2A5B7F,0xF183,0x5C66,{ 0x99,0xB2,0x42,0x90,0x82,0x06,0x92,0x99 } }; // FF2A5B7F-F183-5C66-99B2-429082069299
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IWindowingEnvironmentChangedEventArgs>{ 0x4160CFC6,0x023D,0x5E9A,{ 0xB4,0x31,0x35,0x0E,0x67,0xDC,0x97,0x8A } }; // 4160CFC6-023D-5E9A-B431-350E67DC978A
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IWindowingEnvironmentRemovedEventArgs>{ 0x2E5B5473,0xBEFF,0x5E53,{ 0x93,0x16,0x7E,0x77,0x5F,0xE5,0x68,0xB3 } }; // 2E5B5473-BEFF-5E53-9316-7E775FE568B3
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::IWindowingEnvironmentStatics>{ 0x874E9FB7,0xC642,0x55AB,{ 0x8A,0xA2,0x16,0x2F,0x73,0x4A,0x9A,0x72 } }; // 874E9FB7-C642-55AB-8AA2-162F734A9A72
    template <> struct default_interface<llm::OS::UI::WindowManagement::AppWindow>{ using type = llm::OS::UI::WindowManagement::IAppWindow; };
    template <> struct default_interface<llm::OS::UI::WindowManagement::AppWindowChangedEventArgs>{ using type = llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs; };
    template <> struct default_interface<llm::OS::UI::WindowManagement::AppWindowCloseRequestedEventArgs>{ using type = llm::OS::UI::WindowManagement::IAppWindowCloseRequestedEventArgs; };
    template <> struct default_interface<llm::OS::UI::WindowManagement::AppWindowClosedEventArgs>{ using type = llm::OS::UI::WindowManagement::IAppWindowClosedEventArgs; };
    template <> struct default_interface<llm::OS::UI::WindowManagement::AppWindowFrame>{ using type = llm::OS::UI::WindowManagement::IAppWindowFrame; };
    template <> struct default_interface<llm::OS::UI::WindowManagement::AppWindowPlacement>{ using type = llm::OS::UI::WindowManagement::IAppWindowPlacement; };
    template <> struct default_interface<llm::OS::UI::WindowManagement::AppWindowPresentationConfiguration>{ using type = llm::OS::UI::WindowManagement::IAppWindowPresentationConfiguration; };
    template <> struct default_interface<llm::OS::UI::WindowManagement::AppWindowPresenter>{ using type = llm::OS::UI::WindowManagement::IAppWindowPresenter; };
    template <> struct default_interface<llm::OS::UI::WindowManagement::AppWindowTitleBar>{ using type = llm::OS::UI::WindowManagement::IAppWindowTitleBar; };
    template <> struct default_interface<llm::OS::UI::WindowManagement::AppWindowTitleBarOcclusion>{ using type = llm::OS::UI::WindowManagement::IAppWindowTitleBarOcclusion; };
    template <> struct default_interface<llm::OS::UI::WindowManagement::CompactOverlayPresentationConfiguration>{ using type = llm::OS::UI::WindowManagement::ICompactOverlayPresentationConfiguration; };
    template <> struct default_interface<llm::OS::UI::WindowManagement::DefaultPresentationConfiguration>{ using type = llm::OS::UI::WindowManagement::IDefaultPresentationConfiguration; };
    template <> struct default_interface<llm::OS::UI::WindowManagement::DisplayRegion>{ using type = llm::OS::UI::WindowManagement::IDisplayRegion; };
    template <> struct default_interface<llm::OS::UI::WindowManagement::FullScreenPresentationConfiguration>{ using type = llm::OS::UI::WindowManagement::IFullScreenPresentationConfiguration; };
    template <> struct default_interface<llm::OS::UI::WindowManagement::WindowingEnvironment>{ using type = llm::OS::UI::WindowManagement::IWindowingEnvironment; };
    template <> struct default_interface<llm::OS::UI::WindowManagement::WindowingEnvironmentAddedEventArgs>{ using type = llm::OS::UI::WindowManagement::IWindowingEnvironmentAddedEventArgs; };
    template <> struct default_interface<llm::OS::UI::WindowManagement::WindowingEnvironmentChangedEventArgs>{ using type = llm::OS::UI::WindowManagement::IWindowingEnvironmentChangedEventArgs; };
    template <> struct default_interface<llm::OS::UI::WindowManagement::WindowingEnvironmentRemovedEventArgs>{ using type = llm::OS::UI::WindowManagement::IWindowingEnvironmentRemovedEventArgs; };
    template <> struct abi<llm::OS::UI::WindowManagement::IAppWindow>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Content(void**) noexcept = 0;
            virtual int32_t __stdcall get_DispatcherQueue(void**) noexcept = 0;
            virtual int32_t __stdcall get_Frame(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsVisible(bool*) noexcept = 0;
            virtual int32_t __stdcall get_PersistedStateId(void**) noexcept = 0;
            virtual int32_t __stdcall put_PersistedStateId(void*) noexcept = 0;
            virtual int32_t __stdcall get_Presenter(void**) noexcept = 0;
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall put_Title(void*) noexcept = 0;
            virtual int32_t __stdcall get_TitleBar(void**) noexcept = 0;
            virtual int32_t __stdcall get_UIContext(void**) noexcept = 0;
            virtual int32_t __stdcall get_WindowingEnvironment(void**) noexcept = 0;
            virtual int32_t __stdcall CloseAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetPlacement(void**) noexcept = 0;
            virtual int32_t __stdcall GetDisplayRegions(void**) noexcept = 0;
            virtual int32_t __stdcall RequestMoveToDisplayRegion(void*) noexcept = 0;
            virtual int32_t __stdcall RequestMoveAdjacentToCurrentView() noexcept = 0;
            virtual int32_t __stdcall RequestMoveAdjacentToWindow(void*) noexcept = 0;
            virtual int32_t __stdcall RequestMoveRelativeToWindowContent(void*, llm::OS::Foundation::Point) noexcept = 0;
            virtual int32_t __stdcall RequestMoveRelativeToCurrentViewContent(llm::OS::Foundation::Point) noexcept = 0;
            virtual int32_t __stdcall RequestMoveRelativeToDisplayRegion(void*, llm::OS::Foundation::Point) noexcept = 0;
            virtual int32_t __stdcall RequestSize(llm::OS::Foundation::Size) noexcept = 0;
            virtual int32_t __stdcall TryShowAsync(void**) noexcept = 0;
            virtual int32_t __stdcall add_Changed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Changed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Closed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Closed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_CloseRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_CloseRequested(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DidAvailableWindowPresentationsChange(bool*) noexcept = 0;
            virtual int32_t __stdcall get_DidDisplayRegionsChange(bool*) noexcept = 0;
            virtual int32_t __stdcall get_DidFrameChange(bool*) noexcept = 0;
            virtual int32_t __stdcall get_DidSizeChange(bool*) noexcept = 0;
            virtual int32_t __stdcall get_DidTitleBarChange(bool*) noexcept = 0;
            virtual int32_t __stdcall get_DidVisibilityChange(bool*) noexcept = 0;
            virtual int32_t __stdcall get_DidWindowingEnvironmentChange(bool*) noexcept = 0;
            virtual int32_t __stdcall get_DidWindowPresentationChange(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IAppWindowCloseRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Cancel(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Cancel(bool) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IAppWindowClosedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Reason(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IAppWindowFrame>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DragRegionVisuals(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IAppWindowFrameStyle>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetFrameStyle(int32_t*) noexcept = 0;
            virtual int32_t __stdcall SetFrameStyle(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IAppWindowPlacement>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DisplayRegion(void**) noexcept = 0;
            virtual int32_t __stdcall get_Offset(llm::OS::Foundation::Point*) noexcept = 0;
            virtual int32_t __stdcall get_Size(llm::OS::Foundation::Size*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IAppWindowPresentationConfiguration>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IAppWindowPresentationConfigurationFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IAppWindowPresenter>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetConfiguration(void**) noexcept = 0;
            virtual int32_t __stdcall IsPresentationSupported(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall RequestPresentation(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall RequestPresentationByKind(int32_t, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IAppWindowStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryCreateAsync(void**) noexcept = 0;
            virtual int32_t __stdcall ClearAllPersistedState() noexcept = 0;
            virtual int32_t __stdcall ClearPersistedState(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IAppWindowTitleBar>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_BackgroundColor(void**) noexcept = 0;
            virtual int32_t __stdcall put_BackgroundColor(void*) noexcept = 0;
            virtual int32_t __stdcall get_ButtonBackgroundColor(void**) noexcept = 0;
            virtual int32_t __stdcall put_ButtonBackgroundColor(void*) noexcept = 0;
            virtual int32_t __stdcall get_ButtonForegroundColor(void**) noexcept = 0;
            virtual int32_t __stdcall put_ButtonForegroundColor(void*) noexcept = 0;
            virtual int32_t __stdcall get_ButtonHoverBackgroundColor(void**) noexcept = 0;
            virtual int32_t __stdcall put_ButtonHoverBackgroundColor(void*) noexcept = 0;
            virtual int32_t __stdcall get_ButtonHoverForegroundColor(void**) noexcept = 0;
            virtual int32_t __stdcall put_ButtonHoverForegroundColor(void*) noexcept = 0;
            virtual int32_t __stdcall get_ButtonInactiveBackgroundColor(void**) noexcept = 0;
            virtual int32_t __stdcall put_ButtonInactiveBackgroundColor(void*) noexcept = 0;
            virtual int32_t __stdcall get_ButtonInactiveForegroundColor(void**) noexcept = 0;
            virtual int32_t __stdcall put_ButtonInactiveForegroundColor(void*) noexcept = 0;
            virtual int32_t __stdcall get_ButtonPressedBackgroundColor(void**) noexcept = 0;
            virtual int32_t __stdcall put_ButtonPressedBackgroundColor(void*) noexcept = 0;
            virtual int32_t __stdcall get_ButtonPressedForegroundColor(void**) noexcept = 0;
            virtual int32_t __stdcall put_ButtonPressedForegroundColor(void*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendsContentIntoTitleBar(bool*) noexcept = 0;
            virtual int32_t __stdcall put_ExtendsContentIntoTitleBar(bool) noexcept = 0;
            virtual int32_t __stdcall get_ForegroundColor(void**) noexcept = 0;
            virtual int32_t __stdcall put_ForegroundColor(void*) noexcept = 0;
            virtual int32_t __stdcall get_InactiveBackgroundColor(void**) noexcept = 0;
            virtual int32_t __stdcall put_InactiveBackgroundColor(void*) noexcept = 0;
            virtual int32_t __stdcall get_InactiveForegroundColor(void**) noexcept = 0;
            virtual int32_t __stdcall put_InactiveForegroundColor(void*) noexcept = 0;
            virtual int32_t __stdcall get_IsVisible(bool*) noexcept = 0;
            virtual int32_t __stdcall GetTitleBarOcclusions(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IAppWindowTitleBarOcclusion>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OccludingRect(llm::OS::Foundation::Rect*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IAppWindowTitleBarVisibility>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetPreferredVisibility(int32_t*) noexcept = 0;
            virtual int32_t __stdcall SetPreferredVisibility(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::ICompactOverlayPresentationConfiguration>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IDefaultPresentationConfiguration>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IDisplayRegion>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DisplayMonitorDeviceId(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsVisible(bool*) noexcept = 0;
            virtual int32_t __stdcall get_WorkAreaOffset(llm::OS::Foundation::Point*) noexcept = 0;
            virtual int32_t __stdcall get_WorkAreaSize(llm::OS::Foundation::Size*) noexcept = 0;
            virtual int32_t __stdcall get_WindowingEnvironment(void**) noexcept = 0;
            virtual int32_t __stdcall add_Changed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Changed(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IFullScreenPresentationConfiguration>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsExclusive(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsExclusive(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IWindowServicesStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FindAllTopLevelWindowIds(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IWindowingEnvironment>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetDisplayRegions(void**) noexcept = 0;
            virtual int32_t __stdcall add_Changed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Changed(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IWindowingEnvironmentAddedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_WindowingEnvironment(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IWindowingEnvironmentChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IWindowingEnvironmentRemovedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_WindowingEnvironment(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::IWindowingEnvironmentStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FindAll(void**) noexcept = 0;
            virtual int32_t __stdcall FindAllWithKind(int32_t, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IAppWindow
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::UIContentRoot) Content() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::System::DispatcherQueue) DispatcherQueue() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowFrame) Frame() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsVisible() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PersistedStateId() const;
        LLM_IMPL_AUTO(void) PersistedStateId(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowPresenter) Presenter() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Title() const;
        LLM_IMPL_AUTO(void) Title(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowTitleBar) TitleBar() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::UIContext) UIContext() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::WindowingEnvironment) WindowingEnvironment() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) CloseAsync() const;
        LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowPlacement) GetPlacement() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::DisplayRegion>) GetDisplayRegions() const;
        LLM_IMPL_AUTO(void) RequestMoveToDisplayRegion(llm::OS::UI::WindowManagement::DisplayRegion const& displayRegion) const;
        LLM_IMPL_AUTO(void) RequestMoveAdjacentToCurrentView() const;
        LLM_IMPL_AUTO(void) RequestMoveAdjacentToWindow(llm::OS::UI::WindowManagement::AppWindow const& anchorWindow) const;
        LLM_IMPL_AUTO(void) RequestMoveRelativeToWindowContent(llm::OS::UI::WindowManagement::AppWindow const& anchorWindow, llm::OS::Foundation::Point const& contentOffset) const;
        LLM_IMPL_AUTO(void) RequestMoveRelativeToCurrentViewContent(llm::OS::Foundation::Point const& contentOffset) const;
        LLM_IMPL_AUTO(void) RequestMoveRelativeToDisplayRegion(llm::OS::UI::WindowManagement::DisplayRegion const& displayRegion, llm::OS::Foundation::Point const& displayRegionOffset) const;
        LLM_IMPL_AUTO(void) RequestSize(llm::OS::Foundation::Size const& frameSize) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) TryShowAsync() const;
        LLM_IMPL_AUTO(llm::event_token) Changed(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::AppWindow, llm::OS::UI::WindowManagement::AppWindowChangedEventArgs> const& handler) const;
        using Changed_revoker = impl::event_revoker<llm::OS::UI::WindowManagement::IAppWindow, &impl::abi_t<llm::OS::UI::WindowManagement::IAppWindow>::remove_Changed>;
        [[nodiscard]] Changed_revoker Changed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::AppWindow, llm::OS::UI::WindowManagement::AppWindowChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Changed(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Closed(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::AppWindow, llm::OS::UI::WindowManagement::AppWindowClosedEventArgs> const& handler) const;
        using Closed_revoker = impl::event_revoker<llm::OS::UI::WindowManagement::IAppWindow, &impl::abi_t<llm::OS::UI::WindowManagement::IAppWindow>::remove_Closed>;
        [[nodiscard]] Closed_revoker Closed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::AppWindow, llm::OS::UI::WindowManagement::AppWindowClosedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Closed(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) CloseRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::AppWindow, llm::OS::UI::WindowManagement::AppWindowCloseRequestedEventArgs> const& handler) const;
        using CloseRequested_revoker = impl::event_revoker<llm::OS::UI::WindowManagement::IAppWindow, &impl::abi_t<llm::OS::UI::WindowManagement::IAppWindow>::remove_CloseRequested>;
        [[nodiscard]] CloseRequested_revoker CloseRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::AppWindow, llm::OS::UI::WindowManagement::AppWindowCloseRequestedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) CloseRequested(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IAppWindow>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IAppWindow<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IAppWindowChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) DidAvailableWindowPresentationsChange() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) DidDisplayRegionsChange() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) DidFrameChange() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) DidSizeChange() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) DidTitleBarChange() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) DidVisibilityChange() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) DidWindowingEnvironmentChange() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) DidWindowPresentationChange() const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IAppWindowChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IAppWindowCloseRequestedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Cancel() const;
        LLM_IMPL_AUTO(void) Cancel(bool value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IAppWindowCloseRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IAppWindowCloseRequestedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IAppWindowClosedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowClosedReason) Reason() const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IAppWindowClosedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IAppWindowClosedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IAppWindowFrame
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Composition::IVisualElement>) DragRegionVisuals() const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IAppWindowFrame>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IAppWindowFrame<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IAppWindowFrameStyle
    {
        LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowFrameStyle) GetFrameStyle() const;
        LLM_IMPL_AUTO(void) SetFrameStyle(llm::OS::UI::WindowManagement::AppWindowFrameStyle const& frameStyle) const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IAppWindowFrameStyle>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IAppWindowFrameStyle<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IAppWindowPlacement
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::DisplayRegion) DisplayRegion() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Point) Offset() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Size) Size() const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IAppWindowPlacement>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IAppWindowPlacement<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IAppWindowPresentationConfiguration
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowPresentationKind) Kind() const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IAppWindowPresentationConfiguration>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IAppWindowPresentationConfiguration<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IAppWindowPresentationConfigurationFactory
    {
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IAppWindowPresentationConfigurationFactory>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IAppWindowPresentationConfigurationFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IAppWindowPresenter
    {
        LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowPresentationConfiguration) GetConfiguration() const;
        LLM_IMPL_AUTO(bool) IsPresentationSupported(llm::OS::UI::WindowManagement::AppWindowPresentationKind const& presentationKind) const;
        LLM_IMPL_AUTO(bool) RequestPresentation(llm::OS::UI::WindowManagement::AppWindowPresentationConfiguration const& configuration) const;
        LLM_IMPL_AUTO(bool) RequestPresentation(llm::OS::UI::WindowManagement::AppWindowPresentationKind const& presentationKind) const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IAppWindowPresenter>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IAppWindowPresenter<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IAppWindowStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::UI::WindowManagement::AppWindow>) TryCreateAsync() const;
        LLM_IMPL_AUTO(void) ClearAllPersistedState() const;
        LLM_IMPL_AUTO(void) ClearPersistedState(param::hstring const& key) const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IAppWindowStatics>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IAppWindowStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IAppWindowTitleBar
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) BackgroundColor() const;
        LLM_IMPL_AUTO(void) BackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ButtonBackgroundColor() const;
        LLM_IMPL_AUTO(void) ButtonBackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ButtonForegroundColor() const;
        LLM_IMPL_AUTO(void) ButtonForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ButtonHoverBackgroundColor() const;
        LLM_IMPL_AUTO(void) ButtonHoverBackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ButtonHoverForegroundColor() const;
        LLM_IMPL_AUTO(void) ButtonHoverForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ButtonInactiveBackgroundColor() const;
        LLM_IMPL_AUTO(void) ButtonInactiveBackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ButtonInactiveForegroundColor() const;
        LLM_IMPL_AUTO(void) ButtonInactiveForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ButtonPressedBackgroundColor() const;
        LLM_IMPL_AUTO(void) ButtonPressedBackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ButtonPressedForegroundColor() const;
        LLM_IMPL_AUTO(void) ButtonPressedForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) ExtendsContentIntoTitleBar() const;
        LLM_IMPL_AUTO(void) ExtendsContentIntoTitleBar(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ForegroundColor() const;
        LLM_IMPL_AUTO(void) ForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) InactiveBackgroundColor() const;
        LLM_IMPL_AUTO(void) InactiveBackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) InactiveForegroundColor() const;
        LLM_IMPL_AUTO(void) InactiveForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsVisible() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::AppWindowTitleBarOcclusion>) GetTitleBarOcclusions() const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IAppWindowTitleBar>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IAppWindowTitleBarOcclusion
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Rect) OccludingRect() const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IAppWindowTitleBarOcclusion>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IAppWindowTitleBarOcclusion<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IAppWindowTitleBarVisibility
    {
        LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowTitleBarVisibility) GetPreferredVisibility() const;
        LLM_IMPL_AUTO(void) SetPreferredVisibility(llm::OS::UI::WindowManagement::AppWindowTitleBarVisibility const& visibilityMode) const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IAppWindowTitleBarVisibility>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IAppWindowTitleBarVisibility<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_ICompactOverlayPresentationConfiguration
    {
    };
    template <> struct consume<llm::OS::UI::WindowManagement::ICompactOverlayPresentationConfiguration>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_ICompactOverlayPresentationConfiguration<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IDefaultPresentationConfiguration
    {
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IDefaultPresentationConfiguration>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IDefaultPresentationConfiguration<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IDisplayRegion
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayMonitorDeviceId() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsVisible() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Point) WorkAreaOffset() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Size) WorkAreaSize() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::WindowingEnvironment) WindowingEnvironment() const;
        LLM_IMPL_AUTO(llm::event_token) Changed(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::DisplayRegion, llm::OS::Foundation::IInspectable> const& handler) const;
        using Changed_revoker = impl::event_revoker<llm::OS::UI::WindowManagement::IDisplayRegion, &impl::abi_t<llm::OS::UI::WindowManagement::IDisplayRegion>::remove_Changed>;
        [[nodiscard]] Changed_revoker Changed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::DisplayRegion, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Changed(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IDisplayRegion>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IDisplayRegion<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IFullScreenPresentationConfiguration
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsExclusive() const;
        LLM_IMPL_AUTO(void) IsExclusive(bool value) const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IFullScreenPresentationConfiguration>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IFullScreenPresentationConfiguration<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IWindowServicesStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowId>) FindAllTopLevelWindowIds() const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IWindowServicesStatics>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IWindowServicesStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IWindowingEnvironment
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsEnabled() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::WindowingEnvironmentKind) Kind() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::DisplayRegion>) GetDisplayRegions() const;
        LLM_IMPL_AUTO(llm::event_token) Changed(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::WindowingEnvironment, llm::OS::UI::WindowManagement::WindowingEnvironmentChangedEventArgs> const& handler) const;
        using Changed_revoker = impl::event_revoker<llm::OS::UI::WindowManagement::IWindowingEnvironment, &impl::abi_t<llm::OS::UI::WindowManagement::IWindowingEnvironment>::remove_Changed>;
        [[nodiscard]] Changed_revoker Changed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::WindowingEnvironment, llm::OS::UI::WindowManagement::WindowingEnvironmentChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Changed(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IWindowingEnvironment>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IWindowingEnvironment<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IWindowingEnvironmentAddedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::WindowingEnvironment) WindowingEnvironment() const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IWindowingEnvironmentAddedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IWindowingEnvironmentAddedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IWindowingEnvironmentChangedEventArgs
    {
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IWindowingEnvironmentChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IWindowingEnvironmentChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IWindowingEnvironmentRemovedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::WindowingEnvironment) WindowingEnvironment() const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IWindowingEnvironmentRemovedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IWindowingEnvironmentRemovedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_IWindowingEnvironmentStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::WindowingEnvironment>) FindAll() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::WindowingEnvironment>) FindAll(llm::OS::UI::WindowManagement::WindowingEnvironmentKind const& kind) const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::IWindowingEnvironmentStatics>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_IWindowingEnvironmentStatics<D>;
    };
}
#endif
