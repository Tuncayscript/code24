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
#ifndef LLM_OS_System_0_H
#define LLM_OS_System_0_H
LLM_EXPORT namespace llm:OS::ApplicationModel
{
    struct AppInfo;
}
LLM_EXPORT namespace llm:OS::Foundation
{
    struct Deferral;
    template <typename T> struct __declspec(empty_bases) EventHandler;
    struct EventRegistrationToken;
    struct HResult;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    struct Point;
    struct Rect;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
    struct Uri;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    struct IPropertySet;
    template <typename T> struct __declspec(empty_bases) IVectorView;
    template <typename T> struct __declspec(empty_bases) IVector;
    struct ValueSet;
}
LLM_EXPORT namespace llm:OS::Storage
{
    struct IStorageFile;
    struct IStorageFolder;
    struct IStorageItem;
    struct StorageFile;
}
LLM_EXPORT namespace llm:OS::Storage::Search
{
    struct StorageFileQueryResult;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IInputStream;
    struct IOutputStream;
    struct IRandomAccessStreamReference;
}
LLM_EXPORT namespace llm:OS::System::Diagnostics
{
    struct ProcessDiagnosticInfo;
}
LLM_EXPORT namespace llm:OS::System::RemoteSystems
{
    struct RemoteSystemConnectionRequest;
}
LLM_EXPORT namespace llm:OS::UI::Popups
{
    enum class Placement : int32_t;
}
LLM_EXPORT namespace llm:OS::UI::ViewManagement
{
    enum class ViewSizePreference : int32_t;
}
LLM_EXPORT namespace llm:OS::System
{
    enum class AppDiagnosticInfoWatcherStatus : int32_t
    {
        Created = 0,
        Started = 1,
        EnumerationCompleted = 2,
        Stopping = 3,
        Stopped = 4,
        Aborted = 5,
    };
    enum class AppMemoryUsageLevel : int32_t
    {
        Low = 0,
        Medium = 1,
        High = 2,
        OverLimit = 3,
    };
    enum class AppResourceGroupEnergyQuotaState : int32_t
    {
        Unknown = 0,
        Over = 1,
        Under = 2,
    };
    enum class AppResourceGroupExecutionState : int32_t
    {
        Unknown = 0,
        Running = 1,
        Suspending = 2,
        Suspended = 3,
        NotRunning = 4,
    };
    enum class AppResourceGroupInfoWatcherStatus : int32_t
    {
        Created = 0,
        Started = 1,
        EnumerationCompleted = 2,
        Stopping = 3,
        Stopped = 4,
        Aborted = 5,
    };
    enum class AutoUpdateTimeZoneStatus : int32_t
    {
        Attempted = 0,
        TimedOut = 1,
        Failed = 2,
    };
    enum class DiagnosticAccessStatus : int32_t
    {
        Unspecified = 0,
        Denied = 1,
        Limited = 2,
        Allowed = 3,
    };
    enum class DispatcherQueuePriority : int32_t
    {
        Low = -10,
        Normal = 0,
        High = 10,
    };
    enum class LaunchFileStatus : int32_t
    {
        Success = 0,
        AppUnavailable = 1,
        DeniedByPolicy = 2,
        FileTypeNotSupported = 3,
        Unknown = 4,
    };
    enum class LaunchQuerySupportStatus : int32_t
    {
        Available = 0,
        AppNotInstalled = 1,
        AppUnavailable = 2,
        NotSupported = 3,
        Unknown = 4,
    };
    enum class LaunchQuerySupportType : int32_t
    {
        Uri = 0,
        UriForResults = 1,
    };
    enum class LaunchUriStatus : int32_t
    {
        Success = 0,
        AppUnavailable = 1,
        ProtocolUnavailable = 2,
        Unknown = 3,
    };
    enum class PowerState : int32_t
    {
        ConnectedStandby = 0,
        SleepS3 = 1,
    };
    enum class ProcessorArchitecture : int32_t
    {
        X86 = 0,
        Arm = 5,
        X64 = 9,
        Neutral = 11,
        Arm64 = 12,
        X86OnArm64 = 14,
        Unknown = 65535,
    };
    enum class RemoteLaunchUriStatus : int32_t
    {
        Unknown = 0,
        Success = 1,
        AppUnavailable = 2,
        ProtocolUnavailable = 3,
        RemoteSystemUnavailable = 4,
        ValueSetTooLarge = 5,
        DeniedByLocalSystem = 6,
        DeniedByRemoteSystem = 7,
    };
    enum class ShutdownKind : int32_t
    {
        Shutdown = 0,
        Restart = 1,
    };
    enum class UserAgeConsentGroup : int32_t
    {
        Child = 0,
        Minor = 1,
        Adult = 2,
    };
    enum class UserAgeConsentResult : int32_t
    {
        NotEnforced = 0,
        Included = 1,
        NotIncluded = 2,
        Unknown = 3,
        Ambiguous = 4,
    };
    enum class UserAuthenticationStatus : int32_t
    {
        Unauthenticated = 0,
        LocallyAuthenticated = 1,
        RemotelyAuthenticated = 2,
    };
    enum class UserPictureSize : int32_t
    {
        Size64x64 = 0,
        Size208x208 = 1,
        Size424x424 = 2,
        Size1080x1080 = 3,
    };
    enum class UserType : int32_t
    {
        LocalUser = 0,
        RemoteUser = 1,
        LocalGuest = 2,
        RemoteGuest = 3,
        SystemManaged = 4,
    };
    enum class UserWatcherStatus : int32_t
    {
        Created = 0,
        Started = 1,
        EnumerationCompleted = 2,
        Stopping = 3,
        Stopped = 4,
        Aborted = 5,
    };
    enum class UserWatcherUpdateKind : int32_t
    {
        Properties = 0,
        Picture = 1,
    };
    enum class VirtualKey : int32_t
    {
        None = 0,
        LeftButton = 1,
        RightButton = 2,
        Cancel = 3,
        MiddleButton = 4,
        XButton1 = 5,
        XButton2 = 6,
        Back = 8,
        Tab = 9,
        Clear = 12,
        Enter = 13,
        Shift = 16,
        Control = 17,
        Menu = 18,
        Pause = 19,
        CapitalLock = 20,
        Kana = 21,
        Hangul = 21,
        ImeOn = 22,
        Junja = 23,
        Final = 24,
        Hanja = 25,
        Kanji = 25,
        ImeOff = 26,
        Escape = 27,
        Convert = 28,
        NonConvert = 29,
        Accept = 30,
        ModeChange = 31,
        Space = 32,
        PageUp = 33,
        PageDown = 34,
        End = 35,
        Home = 36,
        Left = 37,
        Up = 38,
        Right = 39,
        Down = 40,
        Select = 41,
        Print = 42,
        Execute = 43,
        Snapshot = 44,
        Insert = 45,
        Delete = 46,
        Help = 47,
        Number0 = 48,
        Number1 = 49,
        Number2 = 50,
        Number3 = 51,
        Number4 = 52,
        Number5 = 53,
        Number6 = 54,
        Number7 = 55,
        Number8 = 56,
        Number9 = 57,
        A = 65,
        B = 66,
        C = 67,
        D = 68,
        E = 69,
        F = 70,
        G = 71,
        H = 72,
        I = 73,
        J = 74,
        K = 75,
        L = 76,
        M = 77,
        N = 78,
        O = 79,
        P = 80,
        Q = 81,
        R = 82,
        S = 83,
        T = 84,
        U = 85,
        V = 86,
        W = 87,
        X = 88,
        Y = 89,
        Z = 90,
        LeftWindows = 91,
        RightWindows = 92,
        Application = 93,
        Sleep = 95,
        NumberPad0 = 96,
        NumberPad1 = 97,
        NumberPad2 = 98,
        NumberPad3 = 99,
        NumberPad4 = 100,
        NumberPad5 = 101,
        NumberPad6 = 102,
        NumberPad7 = 103,
        NumberPad8 = 104,
        NumberPad9 = 105,
        Multiply = 106,
        Add = 107,
        Separator = 108,
        Subtract = 109,
        Decimal = 110,
        Divide = 111,
        F1 = 112,
        F2 = 113,
        F3 = 114,
        F4 = 115,
        F5 = 116,
        F6 = 117,
        F7 = 118,
        F8 = 119,
        F9 = 120,
        F10 = 121,
        F11 = 122,
        F12 = 123,
        F13 = 124,
        F14 = 125,
        F15 = 126,
        F16 = 127,
        F17 = 128,
        F18 = 129,
        F19 = 130,
        F20 = 131,
        F21 = 132,
        F22 = 133,
        F23 = 134,
        F24 = 135,
        NavigationView = 136,
        NavigationMenu = 137,
        NavigationUp = 138,
        NavigationDown = 139,
        NavigationLeft = 140,
        NavigationRight = 141,
        NavigationAccept = 142,
        NavigationCancel = 143,
        NumberKeyLock = 144,
        Scroll = 145,
        LeftShift = 160,
        RightShift = 161,
        LeftControl = 162,
        RightControl = 163,
        LeftMenu = 164,
        RightMenu = 165,
        GoBack = 166,
        GoForward = 167,
        Refresh = 168,
        Stop = 169,
        Search = 170,
        Favorites = 171,
        GoHome = 172,
        GamepadA = 195,
        GamepadB = 196,
        GamepadX = 197,
        GamepadY = 198,
        GamepadRightShoulder = 199,
        GamepadLeftShoulder = 200,
        GamepadLeftTrigger = 201,
        GamepadRightTrigger = 202,
        GamepadDPadUp = 203,
        GamepadDPadDown = 204,
        GamepadDPadLeft = 205,
        GamepadDPadRight = 206,
        GamepadMenu = 207,
        GamepadView = 208,
        GamepadLeftThumbstickButton = 209,
        GamepadRightThumbstickButton = 210,
        GamepadLeftThumbstickUp = 211,
        GamepadLeftThumbstickDown = 212,
        GamepadLeftThumbstickRight = 213,
        GamepadLeftThumbstickLeft = 214,
        GamepadRightThumbstickUp = 215,
        GamepadRightThumbstickDown = 216,
        GamepadRightThumbstickRight = 217,
        GamepadRightThumbstickLeft = 218,
    };
    enum class VirtualKeyModifiers : uint32_t
    {
        None = 0,
        Control = 0x1,
        Menu = 0x2,
        Shift = 0x4,
        Windows = 0x8,
    };
    struct IAppActivationResult;
    struct IAppDiagnosticInfo;
    struct IAppDiagnosticInfo2;
    struct IAppDiagnosticInfo3;
    struct IAppDiagnosticInfoStatics;
    struct IAppDiagnosticInfoStatics2;
    struct IAppDiagnosticInfoWatcher;
    struct IAppDiagnosticInfoWatcherEventArgs;
    struct IAppExecutionStateChangeResult;
    struct IAppMemoryReport;
    struct IAppMemoryReport2;
    struct IAppMemoryUsageLimitChangingEventArgs;
    struct IAppResourceGroupBackgroundTaskReport;
    struct IAppResourceGroupInfo;
    struct IAppResourceGroupInfo2;
    struct IAppResourceGroupInfoWatcher;
    struct IAppResourceGroupInfoWatcherEventArgs;
    struct IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs;
    struct IAppResourceGroupMemoryReport;
    struct IAppResourceGroupStateReport;
    struct IAppUriHandlerHost;
    struct IAppUriHandlerHost2;
    struct IAppUriHandlerHostFactory;
    struct IAppUriHandlerRegistration;
    struct IAppUriHandlerRegistration2;
    struct IAppUriHandlerRegistrationManager;
    struct IAppUriHandlerRegistrationManager2;
    struct IAppUriHandlerRegistrationManagerStatics;
    struct IAppUriHandlerRegistrationManagerStatics2;
    struct IDateTimeSettingsStatics;
    struct IDispatcherQueue;
    struct IDispatcherQueue2;
    struct IDispatcherQueueController;
    struct IDispatcherQueueControllerStatics;
    struct IDispatcherQueueShutdownStartingEventArgs;
    struct IDispatcherQueueStatics;
    struct IDispatcherQueueTimer;
    struct IFolderLauncherOptions;
    struct IKnownUserPropertiesStatics;
    struct IKnownUserPropertiesStatics2;
    struct ILaunchUriResult;
    struct ILauncherOptions;
    struct ILauncherOptions2;
    struct ILauncherOptions3;
    struct ILauncherOptions4;
    struct ILauncherStatics;
    struct ILauncherStatics2;
    struct ILauncherStatics3;
    struct ILauncherStatics4;
    struct ILauncherStatics5;
    struct ILauncherUIOptions;
    struct ILauncherViewOptions;
    struct IMemoryManagerStatics;
    struct IMemoryManagerStatics2;
    struct IMemoryManagerStatics3;
    struct IMemoryManagerStatics4;
    struct IProcessLauncherOptions;
    struct IProcessLauncherResult;
    struct IProcessLauncherStatics;
    struct IProcessMemoryReport;
    struct IProtocolForResultsOperation;
    struct IRemoteLauncherOptions;
    struct IRemoteLauncherStatics;
    struct IShutdownManagerStatics;
    struct IShutdownManagerStatics2;
    struct ITimeZoneSettingsStatics;
    struct ITimeZoneSettingsStatics2;
    struct IUser;
    struct IUser2;
    struct IUserAuthenticationStatusChangeDeferral;
    struct IUserAuthenticationStatusChangingEventArgs;
    struct IUserChangedEventArgs;
    struct IUserChangedEventArgs2;
    struct IUserDeviceAssociationChangedEventArgs;
    struct IUserDeviceAssociationStatics;
    struct IUserPicker;
    struct IUserPickerStatics;
    struct IUserStatics;
    struct IUserStatics2;
    struct IUserWatcher;
    struct AppActivationResult;
    struct AppDiagnosticInfo;
    struct AppDiagnosticInfoWatcher;
    struct AppDiagnosticInfoWatcherEventArgs;
    struct AppExecutionStateChangeResult;
    struct AppMemoryReport;
    struct AppMemoryUsageLimitChangingEventArgs;
    struct AppResourceGroupBackgroundTaskReport;
    struct AppResourceGroupInfo;
    struct AppResourceGroupInfoWatcher;
    struct AppResourceGroupInfoWatcherEventArgs;
    struct AppResourceGroupInfoWatcherExecutionStateChangedEventArgs;
    struct AppResourceGroupMemoryReport;
    struct AppResourceGroupStateReport;
    struct AppUriHandlerHost;
    struct AppUriHandlerRegistration;
    struct AppUriHandlerRegistrationManager;
    struct DateTimeSettings;
    struct DispatcherQueue;
    struct DispatcherQueueController;
    struct DispatcherQueueShutdownStartingEventArgs;
    struct DispatcherQueueTimer;
    struct FolderLauncherOptions;
    struct KnownUserProperties;
    struct LaunchUriResult;
    struct Launcher;
    struct LauncherOptions;
    struct LauncherUIOptions;
    struct MemoryManager;
    struct ProcessLauncher;
    struct ProcessLauncherOptions;
    struct ProcessLauncherResult;
    struct ProcessMemoryReport;
    struct ProtocolForResultsOperation;
    struct RemoteLauncher;
    struct RemoteLauncherOptions;
    struct ShutdownManager;
    struct TimeZoneSettings;
    struct User;
    struct UserAuthenticationStatusChangeDeferral;
    struct UserAuthenticationStatusChangingEventArgs;
    struct UserChangedEventArgs;
    struct UserDeviceAssociation;
    struct UserDeviceAssociationChangedEventArgs;
    struct UserPicker;
    struct UserWatcher;
    struct DispatcherQueueHandler;
}
namespace llm::impl
{
    template <> struct category<llm:OS::System::IAppActivationResult>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppDiagnosticInfo>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppDiagnosticInfo2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppDiagnosticInfo3>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppDiagnosticInfoStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppDiagnosticInfoStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppDiagnosticInfoWatcher>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppDiagnosticInfoWatcherEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppExecutionStateChangeResult>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppMemoryReport>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppMemoryReport2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppMemoryUsageLimitChangingEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppResourceGroupBackgroundTaskReport>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppResourceGroupInfo>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppResourceGroupInfo2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppResourceGroupInfoWatcher>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppResourceGroupInfoWatcherEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppResourceGroupMemoryReport>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppResourceGroupStateReport>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppUriHandlerHost>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppUriHandlerHost2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppUriHandlerHostFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppUriHandlerRegistration>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppUriHandlerRegistration2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppUriHandlerRegistrationManager>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppUriHandlerRegistrationManager2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppUriHandlerRegistrationManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IAppUriHandlerRegistrationManagerStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IDateTimeSettingsStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IDispatcherQueue>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IDispatcherQueue2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IDispatcherQueueController>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IDispatcherQueueControllerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IDispatcherQueueShutdownStartingEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IDispatcherQueueStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IDispatcherQueueTimer>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IFolderLauncherOptions>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IKnownUserPropertiesStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IKnownUserPropertiesStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::ILaunchUriResult>{ using type = interface_category; };
    template <> struct category<llm:OS::System::ILauncherOptions>{ using type = interface_category; };
    template <> struct category<llm:OS::System::ILauncherOptions2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::ILauncherOptions3>{ using type = interface_category; };
    template <> struct category<llm:OS::System::ILauncherOptions4>{ using type = interface_category; };
    template <> struct category<llm:OS::System::ILauncherStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::ILauncherStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::ILauncherStatics3>{ using type = interface_category; };
    template <> struct category<llm:OS::System::ILauncherStatics4>{ using type = interface_category; };
    template <> struct category<llm:OS::System::ILauncherStatics5>{ using type = interface_category; };
    template <> struct category<llm:OS::System::ILauncherUIOptions>{ using type = interface_category; };
    template <> struct category<llm:OS::System::ILauncherViewOptions>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IMemoryManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IMemoryManagerStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IMemoryManagerStatics3>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IMemoryManagerStatics4>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IProcessLauncherOptions>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IProcessLauncherResult>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IProcessLauncherStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IProcessMemoryReport>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IProtocolForResultsOperation>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IRemoteLauncherOptions>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IRemoteLauncherStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IShutdownManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IShutdownManagerStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::ITimeZoneSettingsStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::ITimeZoneSettingsStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IUser>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IUser2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IUserAuthenticationStatusChangeDeferral>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IUserAuthenticationStatusChangingEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IUserChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IUserChangedEventArgs2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IUserDeviceAssociationChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IUserDeviceAssociationStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IUserPicker>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IUserPickerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IUserStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IUserStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::System::IUserWatcher>{ using type = interface_category; };
    template <> struct category<llm:OS::System::AppActivationResult>{ using type = class_category; };
    template <> struct category<llm:OS::System::AppDiagnosticInfo>{ using type = class_category; };
    template <> struct category<llm:OS::System::AppDiagnosticInfoWatcher>{ using type = class_category; };
    template <> struct category<llm:OS::System::AppDiagnosticInfoWatcherEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::System::AppExecutionStateChangeResult>{ using type = class_category; };
    template <> struct category<llm:OS::System::AppMemoryReport>{ using type = class_category; };
    template <> struct category<llm:OS::System::AppMemoryUsageLimitChangingEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::System::AppResourceGroupBackgroundTaskReport>{ using type = class_category; };
    template <> struct category<llm:OS::System::AppResourceGroupInfo>{ using type = class_category; };
    template <> struct category<llm:OS::System::AppResourceGroupInfoWatcher>{ using type = class_category; };
    template <> struct category<llm:OS::System::AppResourceGroupInfoWatcherEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::System::AppResourceGroupInfoWatcherExecutionStateChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::System::AppResourceGroupMemoryReport>{ using type = class_category; };
    template <> struct category<llm:OS::System::AppResourceGroupStateReport>{ using type = class_category; };
    template <> struct category<llm:OS::System::AppUriHandlerHost>{ using type = class_category; };
    template <> struct category<llm:OS::System::AppUriHandlerRegistration>{ using type = class_category; };
    template <> struct category<llm:OS::System::AppUriHandlerRegistrationManager>{ using type = class_category; };
    template <> struct category<llm:OS::System::DateTimeSettings>{ using type = class_category; };
    template <> struct category<llm:OS::System::DispatcherQueue>{ using type = class_category; };
    template <> struct category<llm:OS::System::DispatcherQueueController>{ using type = class_category; };
    template <> struct category<llm:OS::System::DispatcherQueueShutdownStartingEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::System::DispatcherQueueTimer>{ using type = class_category; };
    template <> struct category<llm:OS::System::FolderLauncherOptions>{ using type = class_category; };
    template <> struct category<llm:OS::System::KnownUserProperties>{ using type = class_category; };
    template <> struct category<llm:OS::System::LaunchUriResult>{ using type = class_category; };
    template <> struct category<llm:OS::System::Launcher>{ using type = class_category; };
    template <> struct category<llm:OS::System::LauncherOptions>{ using type = class_category; };
    template <> struct category<llm:OS::System::LauncherUIOptions>{ using type = class_category; };
    template <> struct category<llm:OS::System::MemoryManager>{ using type = class_category; };
    template <> struct category<llm:OS::System::ProcessLauncher>{ using type = class_category; };
    template <> struct category<llm:OS::System::ProcessLauncherOptions>{ using type = class_category; };
    template <> struct category<llm:OS::System::ProcessLauncherResult>{ using type = class_category; };
    template <> struct category<llm:OS::System::ProcessMemoryReport>{ using type = class_category; };
    template <> struct category<llm:OS::System::ProtocolForResultsOperation>{ using type = class_category; };
    template <> struct category<llm:OS::System::RemoteLauncher>{ using type = class_category; };
    template <> struct category<llm:OS::System::RemoteLauncherOptions>{ using type = class_category; };
    template <> struct category<llm:OS::System::ShutdownManager>{ using type = class_category; };
    template <> struct category<llm:OS::System::TimeZoneSettings>{ using type = class_category; };
    template <> struct category<llm:OS::System::User>{ using type = class_category; };
    template <> struct category<llm:OS::System::UserAuthenticationStatusChangeDeferral>{ using type = class_category; };
    template <> struct category<llm:OS::System::UserAuthenticationStatusChangingEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::System::UserChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::System::UserDeviceAssociation>{ using type = class_category; };
    template <> struct category<llm:OS::System::UserDeviceAssociationChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::System::UserPicker>{ using type = class_category; };
    template <> struct category<llm:OS::System::UserWatcher>{ using type = class_category; };
    template <> struct category<llm:OS::System::AppDiagnosticInfoWatcherStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::System::AppMemoryUsageLevel>{ using type = enum_category; };
    template <> struct category<llm:OS::System::AppResourceGroupEnergyQuotaState>{ using type = enum_category; };
    template <> struct category<llm:OS::System::AppResourceGroupExecutionState>{ using type = enum_category; };
    template <> struct category<llm:OS::System::AppResourceGroupInfoWatcherStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::System::AutoUpdateTimeZoneStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::System::DiagnosticAccessStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::System::DispatcherQueuePriority>{ using type = enum_category; };
    template <> struct category<llm:OS::System::LaunchFileStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::System::LaunchQuerySupportStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::System::LaunchQuerySupportType>{ using type = enum_category; };
    template <> struct category<llm:OS::System::LaunchUriStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::System::PowerState>{ using type = enum_category; };
    template <> struct category<llm:OS::System::ProcessorArchitecture>{ using type = enum_category; };
    template <> struct category<llm:OS::System::RemoteLaunchUriStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::System::ShutdownKind>{ using type = enum_category; };
    template <> struct category<llm:OS::System::UserAgeConsentGroup>{ using type = enum_category; };
    template <> struct category<llm:OS::System::UserAgeConsentResult>{ using type = enum_category; };
    template <> struct category<llm:OS::System::UserAuthenticationStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::System::UserPictureSize>{ using type = enum_category; };
    template <> struct category<llm:OS::System::UserType>{ using type = enum_category; };
    template <> struct category<llm:OS::System::UserWatcherStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::System::UserWatcherUpdateKind>{ using type = enum_category; };
    template <> struct category<llm:OS::System::VirtualKey>{ using type = enum_category; };
    template <> struct category<llm:OS::System::VirtualKeyModifiers>{ using type = enum_category; };
    template <> struct category<llm:OS::System::DispatcherQueueHandler>{ using type = delegate_category; };
    template <> inline constexpr auto& name_v<llm:OS::System::AppActivationResult> = L"Windows.System.AppActivationResult";
    template <> inline constexpr auto& name_v<llm:OS::System::AppDiagnosticInfo> = L"Windows.System.AppDiagnosticInfo";
    template <> inline constexpr auto& name_v<llm:OS::System::AppDiagnosticInfoWatcher> = L"Windows.System.AppDiagnosticInfoWatcher";
    template <> inline constexpr auto& name_v<llm:OS::System::AppDiagnosticInfoWatcherEventArgs> = L"Windows.System.AppDiagnosticInfoWatcherEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::AppExecutionStateChangeResult> = L"Windows.System.AppExecutionStateChangeResult";
    template <> inline constexpr auto& name_v<llm:OS::System::AppMemoryReport> = L"Windows.System.AppMemoryReport";
    template <> inline constexpr auto& name_v<llm:OS::System::AppMemoryUsageLimitChangingEventArgs> = L"Windows.System.AppMemoryUsageLimitChangingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::AppResourceGroupBackgroundTaskReport> = L"Windows.System.AppResourceGroupBackgroundTaskReport";
    template <> inline constexpr auto& name_v<llm:OS::System::AppResourceGroupInfo> = L"Windows.System.AppResourceGroupInfo";
    template <> inline constexpr auto& name_v<llm:OS::System::AppResourceGroupInfoWatcher> = L"Windows.System.AppResourceGroupInfoWatcher";
    template <> inline constexpr auto& name_v<llm:OS::System::AppResourceGroupInfoWatcherEventArgs> = L"Windows.System.AppResourceGroupInfoWatcherEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::AppResourceGroupInfoWatcherExecutionStateChangedEventArgs> = L"Windows.System.AppResourceGroupInfoWatcherExecutionStateChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::AppResourceGroupMemoryReport> = L"Windows.System.AppResourceGroupMemoryReport";
    template <> inline constexpr auto& name_v<llm:OS::System::AppResourceGroupStateReport> = L"Windows.System.AppResourceGroupStateReport";
    template <> inline constexpr auto& name_v<llm:OS::System::AppUriHandlerHost> = L"Windows.System.AppUriHandlerHost";
    template <> inline constexpr auto& name_v<llm:OS::System::AppUriHandlerRegistration> = L"Windows.System.AppUriHandlerRegistration";
    template <> inline constexpr auto& name_v<llm:OS::System::AppUriHandlerRegistrationManager> = L"Windows.System.AppUriHandlerRegistrationManager";
    template <> inline constexpr auto& name_v<llm:OS::System::DateTimeSettings> = L"Windows.System.DateTimeSettings";
    template <> inline constexpr auto& name_v<llm:OS::System::DispatcherQueue> = L"Windows.System.DispatcherQueue";
    template <> inline constexpr auto& name_v<llm:OS::System::DispatcherQueueController> = L"Windows.System.DispatcherQueueController";
    template <> inline constexpr auto& name_v<llm:OS::System::DispatcherQueueShutdownStartingEventArgs> = L"Windows.System.DispatcherQueueShutdownStartingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::DispatcherQueueTimer> = L"Windows.System.DispatcherQueueTimer";
    template <> inline constexpr auto& name_v<llm:OS::System::FolderLauncherOptions> = L"Windows.System.FolderLauncherOptions";
    template <> inline constexpr auto& name_v<llm:OS::System::KnownUserProperties> = L"Windows.System.KnownUserProperties";
    template <> inline constexpr auto& name_v<llm:OS::System::LaunchUriResult> = L"Windows.System.LaunchUriResult";
    template <> inline constexpr auto& name_v<llm:OS::System::Launcher> = L"Windows.System.Launcher";
    template <> inline constexpr auto& name_v<llm:OS::System::LauncherOptions> = L"Windows.System.LauncherOptions";
    template <> inline constexpr auto& name_v<llm:OS::System::LauncherUIOptions> = L"Windows.System.LauncherUIOptions";
    template <> inline constexpr auto& name_v<llm:OS::System::MemoryManager> = L"Windows.System.MemoryManager";
    template <> inline constexpr auto& name_v<llm:OS::System::ProcessLauncher> = L"Windows.System.ProcessLauncher";
    template <> inline constexpr auto& name_v<llm:OS::System::ProcessLauncherOptions> = L"Windows.System.ProcessLauncherOptions";
    template <> inline constexpr auto& name_v<llm:OS::System::ProcessLauncherResult> = L"Windows.System.ProcessLauncherResult";
    template <> inline constexpr auto& name_v<llm:OS::System::ProcessMemoryReport> = L"Windows.System.ProcessMemoryReport";
    template <> inline constexpr auto& name_v<llm:OS::System::ProtocolForResultsOperation> = L"Windows.System.ProtocolForResultsOperation";
    template <> inline constexpr auto& name_v<llm:OS::System::RemoteLauncher> = L"Windows.System.RemoteLauncher";
    template <> inline constexpr auto& name_v<llm:OS::System::RemoteLauncherOptions> = L"Windows.System.RemoteLauncherOptions";
    template <> inline constexpr auto& name_v<llm:OS::System::ShutdownManager> = L"Windows.System.ShutdownManager";
    template <> inline constexpr auto& name_v<llm:OS::System::TimeZoneSettings> = L"Windows.System.TimeZoneSettings";
    template <> inline constexpr auto& name_v<llm:OS::System::User> = L"Windows.System.User";
    template <> inline constexpr auto& name_v<llm:OS::System::UserAuthenticationStatusChangeDeferral> = L"Windows.System.UserAuthenticationStatusChangeDeferral";
    template <> inline constexpr auto& name_v<llm:OS::System::UserAuthenticationStatusChangingEventArgs> = L"Windows.System.UserAuthenticationStatusChangingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::UserChangedEventArgs> = L"Windows.System.UserChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::UserDeviceAssociation> = L"Windows.System.UserDeviceAssociation";
    template <> inline constexpr auto& name_v<llm:OS::System::UserDeviceAssociationChangedEventArgs> = L"Windows.System.UserDeviceAssociationChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::UserPicker> = L"Windows.System.UserPicker";
    template <> inline constexpr auto& name_v<llm:OS::System::UserWatcher> = L"Windows.System.UserWatcher";
    template <> inline constexpr auto& name_v<llm:OS::System::AppDiagnosticInfoWatcherStatus> = L"Windows.System.AppDiagnosticInfoWatcherStatus";
    template <> inline constexpr auto& name_v<llm:OS::System::AppMemoryUsageLevel> = L"Windows.System.AppMemoryUsageLevel";
    template <> inline constexpr auto& name_v<llm:OS::System::AppResourceGroupEnergyQuotaState> = L"Windows.System.AppResourceGroupEnergyQuotaState";
    template <> inline constexpr auto& name_v<llm:OS::System::AppResourceGroupExecutionState> = L"Windows.System.AppResourceGroupExecutionState";
    template <> inline constexpr auto& name_v<llm:OS::System::AppResourceGroupInfoWatcherStatus> = L"Windows.System.AppResourceGroupInfoWatcherStatus";
    template <> inline constexpr auto& name_v<llm:OS::System::AutoUpdateTimeZoneStatus> = L"Windows.System.AutoUpdateTimeZoneStatus";
    template <> inline constexpr auto& name_v<llm:OS::System::DiagnosticAccessStatus> = L"Windows.System.DiagnosticAccessStatus";
    template <> inline constexpr auto& name_v<llm:OS::System::DispatcherQueuePriority> = L"Windows.System.DispatcherQueuePriority";
    template <> inline constexpr auto& name_v<llm:OS::System::LaunchFileStatus> = L"Windows.System.LaunchFileStatus";
    template <> inline constexpr auto& name_v<llm:OS::System::LaunchQuerySupportStatus> = L"Windows.System.LaunchQuerySupportStatus";
    template <> inline constexpr auto& name_v<llm:OS::System::LaunchQuerySupportType> = L"Windows.System.LaunchQuerySupportType";
    template <> inline constexpr auto& name_v<llm:OS::System::LaunchUriStatus> = L"Windows.System.LaunchUriStatus";
    template <> inline constexpr auto& name_v<llm:OS::System::PowerState> = L"Windows.System.PowerState";
    template <> inline constexpr auto& name_v<llm:OS::System::ProcessorArchitecture> = L"Windows.System.ProcessorArchitecture";
    template <> inline constexpr auto& name_v<llm:OS::System::RemoteLaunchUriStatus> = L"Windows.System.RemoteLaunchUriStatus";
    template <> inline constexpr auto& name_v<llm:OS::System::ShutdownKind> = L"Windows.System.ShutdownKind";
    template <> inline constexpr auto& name_v<llm:OS::System::UserAgeConsentGroup> = L"Windows.System.UserAgeConsentGroup";
    template <> inline constexpr auto& name_v<llm:OS::System::UserAgeConsentResult> = L"Windows.System.UserAgeConsentResult";
    template <> inline constexpr auto& name_v<llm:OS::System::UserAuthenticationStatus> = L"Windows.System.UserAuthenticationStatus";
    template <> inline constexpr auto& name_v<llm:OS::System::UserPictureSize> = L"Windows.System.UserPictureSize";
    template <> inline constexpr auto& name_v<llm:OS::System::UserType> = L"Windows.System.UserType";
    template <> inline constexpr auto& name_v<llm:OS::System::UserWatcherStatus> = L"Windows.System.UserWatcherStatus";
    template <> inline constexpr auto& name_v<llm:OS::System::UserWatcherUpdateKind> = L"Windows.System.UserWatcherUpdateKind";
    template <> inline constexpr auto& name_v<llm:OS::System::VirtualKey> = L"Windows.System.VirtualKey";
    template <> inline constexpr auto& name_v<llm:OS::System::VirtualKeyModifiers> = L"Windows.System.VirtualKeyModifiers";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppActivationResult> = L"Windows.System.IAppActivationResult";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppDiagnosticInfo> = L"Windows.System.IAppDiagnosticInfo";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppDiagnosticInfo2> = L"Windows.System.IAppDiagnosticInfo2";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppDiagnosticInfo3> = L"Windows.System.IAppDiagnosticInfo3";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppDiagnosticInfoStatics> = L"Windows.System.IAppDiagnosticInfoStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppDiagnosticInfoStatics2> = L"Windows.System.IAppDiagnosticInfoStatics2";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppDiagnosticInfoWatcher> = L"Windows.System.IAppDiagnosticInfoWatcher";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppDiagnosticInfoWatcherEventArgs> = L"Windows.System.IAppDiagnosticInfoWatcherEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppExecutionStateChangeResult> = L"Windows.System.IAppExecutionStateChangeResult";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppMemoryReport> = L"Windows.System.IAppMemoryReport";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppMemoryReport2> = L"Windows.System.IAppMemoryReport2";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppMemoryUsageLimitChangingEventArgs> = L"Windows.System.IAppMemoryUsageLimitChangingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppResourceGroupBackgroundTaskReport> = L"Windows.System.IAppResourceGroupBackgroundTaskReport";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppResourceGroupInfo> = L"Windows.System.IAppResourceGroupInfo";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppResourceGroupInfo2> = L"Windows.System.IAppResourceGroupInfo2";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppResourceGroupInfoWatcher> = L"Windows.System.IAppResourceGroupInfoWatcher";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppResourceGroupInfoWatcherEventArgs> = L"Windows.System.IAppResourceGroupInfoWatcherEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs> = L"Windows.System.IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppResourceGroupMemoryReport> = L"Windows.System.IAppResourceGroupMemoryReport";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppResourceGroupStateReport> = L"Windows.System.IAppResourceGroupStateReport";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppUriHandlerHost> = L"Windows.System.IAppUriHandlerHost";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppUriHandlerHost2> = L"Windows.System.IAppUriHandlerHost2";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppUriHandlerHostFactory> = L"Windows.System.IAppUriHandlerHostFactory";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppUriHandlerRegistration> = L"Windows.System.IAppUriHandlerRegistration";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppUriHandlerRegistration2> = L"Windows.System.IAppUriHandlerRegistration2";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppUriHandlerRegistrationManager> = L"Windows.System.IAppUriHandlerRegistrationManager";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppUriHandlerRegistrationManager2> = L"Windows.System.IAppUriHandlerRegistrationManager2";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppUriHandlerRegistrationManagerStatics> = L"Windows.System.IAppUriHandlerRegistrationManagerStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::IAppUriHandlerRegistrationManagerStatics2> = L"Windows.System.IAppUriHandlerRegistrationManagerStatics2";
    template <> inline constexpr auto& name_v<llm:OS::System::IDateTimeSettingsStatics> = L"Windows.System.IDateTimeSettingsStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::IDispatcherQueue> = L"Windows.System.IDispatcherQueue";
    template <> inline constexpr auto& name_v<llm:OS::System::IDispatcherQueue2> = L"Windows.System.IDispatcherQueue2";
    template <> inline constexpr auto& name_v<llm:OS::System::IDispatcherQueueController> = L"Windows.System.IDispatcherQueueController";
    template <> inline constexpr auto& name_v<llm:OS::System::IDispatcherQueueControllerStatics> = L"Windows.System.IDispatcherQueueControllerStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::IDispatcherQueueShutdownStartingEventArgs> = L"Windows.System.IDispatcherQueueShutdownStartingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::IDispatcherQueueStatics> = L"Windows.System.IDispatcherQueueStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::IDispatcherQueueTimer> = L"Windows.System.IDispatcherQueueTimer";
    template <> inline constexpr auto& name_v<llm:OS::System::IFolderLauncherOptions> = L"Windows.System.IFolderLauncherOptions";
    template <> inline constexpr auto& name_v<llm:OS::System::IKnownUserPropertiesStatics> = L"Windows.System.IKnownUserPropertiesStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::IKnownUserPropertiesStatics2> = L"Windows.System.IKnownUserPropertiesStatics2";
    template <> inline constexpr auto& name_v<llm:OS::System::ILaunchUriResult> = L"Windows.System.ILaunchUriResult";
    template <> inline constexpr auto& name_v<llm:OS::System::ILauncherOptions> = L"Windows.System.ILauncherOptions";
    template <> inline constexpr auto& name_v<llm:OS::System::ILauncherOptions2> = L"Windows.System.ILauncherOptions2";
    template <> inline constexpr auto& name_v<llm:OS::System::ILauncherOptions3> = L"Windows.System.ILauncherOptions3";
    template <> inline constexpr auto& name_v<llm:OS::System::ILauncherOptions4> = L"Windows.System.ILauncherOptions4";
    template <> inline constexpr auto& name_v<llm:OS::System::ILauncherStatics> = L"Windows.System.ILauncherStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::ILauncherStatics2> = L"Windows.System.ILauncherStatics2";
    template <> inline constexpr auto& name_v<llm:OS::System::ILauncherStatics3> = L"Windows.System.ILauncherStatics3";
    template <> inline constexpr auto& name_v<llm:OS::System::ILauncherStatics4> = L"Windows.System.ILauncherStatics4";
    template <> inline constexpr auto& name_v<llm:OS::System::ILauncherStatics5> = L"Windows.System.ILauncherStatics5";
    template <> inline constexpr auto& name_v<llm:OS::System::ILauncherUIOptions> = L"Windows.System.ILauncherUIOptions";
    template <> inline constexpr auto& name_v<llm:OS::System::ILauncherViewOptions> = L"Windows.System.ILauncherViewOptions";
    template <> inline constexpr auto& name_v<llm:OS::System::IMemoryManagerStatics> = L"Windows.System.IMemoryManagerStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::IMemoryManagerStatics2> = L"Windows.System.IMemoryManagerStatics2";
    template <> inline constexpr auto& name_v<llm:OS::System::IMemoryManagerStatics3> = L"Windows.System.IMemoryManagerStatics3";
    template <> inline constexpr auto& name_v<llm:OS::System::IMemoryManagerStatics4> = L"Windows.System.IMemoryManagerStatics4";
    template <> inline constexpr auto& name_v<llm:OS::System::IProcessLauncherOptions> = L"Windows.System.IProcessLauncherOptions";
    template <> inline constexpr auto& name_v<llm:OS::System::IProcessLauncherResult> = L"Windows.System.IProcessLauncherResult";
    template <> inline constexpr auto& name_v<llm:OS::System::IProcessLauncherStatics> = L"Windows.System.IProcessLauncherStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::IProcessMemoryReport> = L"Windows.System.IProcessMemoryReport";
    template <> inline constexpr auto& name_v<llm:OS::System::IProtocolForResultsOperation> = L"Windows.System.IProtocolForResultsOperation";
    template <> inline constexpr auto& name_v<llm:OS::System::IRemoteLauncherOptions> = L"Windows.System.IRemoteLauncherOptions";
    template <> inline constexpr auto& name_v<llm:OS::System::IRemoteLauncherStatics> = L"Windows.System.IRemoteLauncherStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::IShutdownManagerStatics> = L"Windows.System.IShutdownManagerStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::IShutdownManagerStatics2> = L"Windows.System.IShutdownManagerStatics2";
    template <> inline constexpr auto& name_v<llm:OS::System::ITimeZoneSettingsStatics> = L"Windows.System.ITimeZoneSettingsStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::ITimeZoneSettingsStatics2> = L"Windows.System.ITimeZoneSettingsStatics2";
    template <> inline constexpr auto& name_v<llm:OS::System::IUser> = L"Windows.System.IUser";
    template <> inline constexpr auto& name_v<llm:OS::System::IUser2> = L"Windows.System.IUser2";
    template <> inline constexpr auto& name_v<llm:OS::System::IUserAuthenticationStatusChangeDeferral> = L"Windows.System.IUserAuthenticationStatusChangeDeferral";
    template <> inline constexpr auto& name_v<llm:OS::System::IUserAuthenticationStatusChangingEventArgs> = L"Windows.System.IUserAuthenticationStatusChangingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::IUserChangedEventArgs> = L"Windows.System.IUserChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::IUserChangedEventArgs2> = L"Windows.System.IUserChangedEventArgs2";
    template <> inline constexpr auto& name_v<llm:OS::System::IUserDeviceAssociationChangedEventArgs> = L"Windows.System.IUserDeviceAssociationChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::IUserDeviceAssociationStatics> = L"Windows.System.IUserDeviceAssociationStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::IUserPicker> = L"Windows.System.IUserPicker";
    template <> inline constexpr auto& name_v<llm:OS::System::IUserPickerStatics> = L"Windows.System.IUserPickerStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::IUserStatics> = L"Windows.System.IUserStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::IUserStatics2> = L"Windows.System.IUserStatics2";
    template <> inline constexpr auto& name_v<llm:OS::System::IUserWatcher> = L"Windows.System.IUserWatcher";
    template <> inline constexpr auto& name_v<llm:OS::System::DispatcherQueueHandler> = L"Windows.System.DispatcherQueueHandler";
    template <> inline constexpr guid guid_v<llm:OS::System::IAppActivationResult>{ 0x6B528900,0xF46E,0x4EB0,{ 0xAA,0x6C,0x38,0xAF,0x55,0x7C,0xF9,0xED } }; // 6B528900-F46E-4EB0-AA6C-38AF557CF9ED
    template <> inline constexpr guid guid_v<llm:OS::System::IAppDiagnosticInfo>{ 0xE348A69A,0x8889,0x4CA3,{ 0xBE,0x07,0xD5,0xFF,0xFF,0x5F,0x08,0x04 } }; // E348A69A-8889-4CA3-BE07-D5FFFF5F0804
    template <> inline constexpr guid guid_v<llm:OS::System::IAppDiagnosticInfo2>{ 0xDF46FBD7,0x191A,0x446C,{ 0x94,0x73,0x8F,0xBC,0x23,0x74,0xA3,0x54 } }; // DF46FBD7-191A-446C-9473-8FBC2374A354
    template <> inline constexpr guid guid_v<llm:OS::System::IAppDiagnosticInfo3>{ 0xC895C63D,0xDD61,0x4C65,{ 0xBA,0xBD,0x81,0xA1,0x0B,0x4F,0x98,0x15 } }; // C895C63D-DD61-4C65-BABD-81A10B4F9815
    template <> inline constexpr guid guid_v<llm:OS::System::IAppDiagnosticInfoStatics>{ 0xCE6925BF,0x10CA,0x40C8,{ 0xA9,0xCA,0xC5,0xC9,0x65,0x01,0x86,0x6E } }; // CE6925BF-10CA-40C8-A9CA-C5C96501866E
    template <> inline constexpr guid guid_v<llm:OS::System::IAppDiagnosticInfoStatics2>{ 0x05B24B86,0x1000,0x4C90,{ 0xBB,0x9F,0x72,0x35,0x07,0x1C,0x50,0xFE } }; // 05B24B86-1000-4C90-BB9F-7235071C50FE
    template <> inline constexpr guid guid_v<llm:OS::System::IAppDiagnosticInfoWatcher>{ 0x75575070,0x01D3,0x489A,{ 0x93,0x25,0x52,0xF9,0xCC,0x6E,0xDE,0x0A } }; // 75575070-01D3-489A-9325-52F9CC6EDE0A
    template <> inline constexpr guid guid_v<llm:OS::System::IAppDiagnosticInfoWatcherEventArgs>{ 0x7017C716,0xE1DA,0x4C65,{ 0x99,0xDF,0x04,0x6D,0xFF,0x5B,0xE7,0x1A } }; // 7017C716-E1DA-4C65-99DF-046DFF5BE71A
    template <> inline constexpr guid guid_v<llm:OS::System::IAppExecutionStateChangeResult>{ 0x6F039BF0,0xF91B,0x4DF8,{ 0xAE,0x77,0x30,0x33,0xCC,0xB6,0x91,0x14 } }; // 6F039BF0-F91B-4DF8-AE77-3033CCB69114
    template <> inline constexpr guid guid_v<llm:OS::System::IAppMemoryReport>{ 0x6D65339B,0x4D6F,0x45BC,{ 0x9C,0x5E,0xE4,0x9B,0x3F,0xF2,0x75,0x8D } }; // 6D65339B-4D6F-45BC-9C5E-E49B3FF2758D
    template <> inline constexpr guid guid_v<llm:OS::System::IAppMemoryReport2>{ 0x5F7F3738,0x51B7,0x42DC,{ 0xB7,0xED,0x79,0xBA,0x46,0xD2,0x88,0x57 } }; // 5F7F3738-51B7-42DC-B7ED-79BA46D28857
    template <> inline constexpr guid guid_v<llm:OS::System::IAppMemoryUsageLimitChangingEventArgs>{ 0x79F86664,0xFECA,0x4DA5,{ 0x9E,0x40,0x2B,0xC6,0x3E,0xFD,0xC9,0x79 } }; // 79F86664-FECA-4DA5-9E40-2BC63EFDC979
    template <> inline constexpr guid guid_v<llm:OS::System::IAppResourceGroupBackgroundTaskReport>{ 0x2566E74E,0xB05D,0x40C2,{ 0x9D,0xC1,0x1A,0x4F,0x03,0x9E,0xA1,0x20 } }; // 2566E74E-B05D-40C2-9DC1-1A4F039EA120
    template <> inline constexpr guid guid_v<llm:OS::System::IAppResourceGroupInfo>{ 0xB913F77A,0xE807,0x49F4,{ 0x84,0x5E,0x7B,0x8B,0xDC,0xFE,0x8E,0xE7 } }; // B913F77A-E807-49F4-845E-7B8BDCFE8EE7
    template <> inline constexpr guid guid_v<llm:OS::System::IAppResourceGroupInfo2>{ 0xEE9B236D,0xD305,0x4D6B,{ 0x92,0xF7,0x6A,0xFD,0xAD,0x72,0xDE,0xDC } }; // EE9B236D-D305-4D6B-92F7-6AFDAD72DEDC
    template <> inline constexpr guid guid_v<llm:OS::System::IAppResourceGroupInfoWatcher>{ 0xD9B0A0FD,0x6E5A,0x4C72,{ 0x8B,0x17,0x09,0xFE,0xC4,0xA2,0x12,0xBD } }; // D9B0A0FD-6E5A-4C72-8B17-09FEC4A212BD
    template <> inline constexpr guid guid_v<llm:OS::System::IAppResourceGroupInfoWatcherEventArgs>{ 0x7A787637,0x6302,0x4D2F,{ 0xBF,0x89,0x1C,0x12,0xD0,0xB2,0xA6,0xB9 } }; // 7A787637-6302-4D2F-BF89-1C12D0B2A6B9
    template <> inline constexpr guid guid_v<llm:OS::System::IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs>{ 0x1BDBEDD7,0xFEE6,0x4FD4,{ 0x98,0xDD,0xE9,0x2A,0x2C,0xC2,0x99,0xF3 } }; // 1BDBEDD7-FEE6-4FD4-98DD-E92A2CC299F3
    template <> inline constexpr guid guid_v<llm:OS::System::IAppResourceGroupMemoryReport>{ 0x2C8C06B1,0x7DB1,0x4C51,{ 0xA2,0x25,0x7F,0xAE,0x2D,0x49,0xE4,0x31 } }; // 2C8C06B1-7DB1-4C51-A225-7FAE2D49E431
    template <> inline constexpr guid guid_v<llm:OS::System::IAppResourceGroupStateReport>{ 0x52849F18,0x2F70,0x4236,{ 0xAB,0x40,0xD0,0x4D,0xB0,0xC7,0xB9,0x31 } }; // 52849F18-2F70-4236-AB40-D04DB0C7B931
    template <> inline constexpr guid guid_v<llm:OS::System::IAppUriHandlerHost>{ 0x5D50CAC5,0x92D2,0x5409,{ 0xB5,0x6F,0x7F,0x73,0xE1,0x0E,0xA4,0xC3 } }; // 5D50CAC5-92D2-5409-B56F-7F73E10EA4C3
    template <> inline constexpr guid guid_v<llm:OS::System::IAppUriHandlerHost2>{ 0x3A0BEE95,0x29E4,0x51BF,{ 0x80,0x95,0xA3,0xC0,0x68,0xE3,0xC7,0x2A } }; // 3A0BEE95-29E4-51BF-8095-A3C068E3C72A
    template <> inline constexpr guid guid_v<llm:OS::System::IAppUriHandlerHostFactory>{ 0x257C3C96,0xCE04,0x5F98,{ 0x96,0xBB,0x3E,0xBD,0x3E,0x92,0x75,0xBB } }; // 257C3C96-CE04-5F98-96BB-3EBD3E9275BB
    template <> inline constexpr guid guid_v<llm:OS::System::IAppUriHandlerRegistration>{ 0x6F73AEB1,0x4569,0x5C3F,{ 0x9B,0xA0,0x99,0x12,0x3E,0xEA,0x32,0xC3 } }; // 6F73AEB1-4569-5C3F-9BA0-99123EEA32C3
    template <> inline constexpr guid guid_v<llm:OS::System::IAppUriHandlerRegistration2>{ 0xD54DAC97,0xCB39,0x5F1F,{ 0x88,0x3E,0x01,0x85,0x37,0x30,0xBD,0x6D } }; // D54DAC97-CB39-5F1F-883E-01853730BD6D
    template <> inline constexpr guid guid_v<llm:OS::System::IAppUriHandlerRegistrationManager>{ 0xE62C9A52,0xAC94,0x5750,{ 0xAC,0x1B,0x6C,0xFB,0x6F,0x25,0x02,0x63 } }; // E62C9A52-AC94-5750-AC1B-6CFB6F250263
    template <> inline constexpr guid guid_v<llm:OS::System::IAppUriHandlerRegistrationManager2>{ 0xBDDFCAF1,0xB51A,0x5E69,{ 0xAE,0xFD,0x70,0x88,0xD9,0xF2,0xB1,0x23 } }; // BDDFCAF1-B51A-5E69-AEFD-7088D9F2B123
    template <> inline constexpr guid guid_v<llm:OS::System::IAppUriHandlerRegistrationManagerStatics>{ 0xD5CEDD9F,0x5729,0x5B76,{ 0xA1,0xD4,0x02,0x85,0xF2,0x95,0xC1,0x24 } }; // D5CEDD9F-5729-5B76-A1D4-0285F295C124
    template <> inline constexpr guid guid_v<llm:OS::System::IAppUriHandlerRegistrationManagerStatics2>{ 0x14F78379,0x6890,0x5080,{ 0x90,0xA7,0x98,0x82,0x4A,0x7F,0x07,0x9E } }; // 14F78379-6890-5080-90A7-98824A7F079E
    template <> inline constexpr guid guid_v<llm:OS::System::IDateTimeSettingsStatics>{ 0x5D2150D1,0x47EE,0x48AB,{ 0xA5,0x2B,0x9F,0x19,0x54,0x27,0x8D,0x82 } }; // 5D2150D1-47EE-48AB-A52B-9F1954278D82
    template <> inline constexpr guid guid_v<llm:OS::System::IDispatcherQueue>{ 0x603E88E4,0xA338,0x4FFE,{ 0xA4,0x57,0xA5,0xCF,0xB9,0xCE,0xB8,0x99 } }; // 603E88E4-A338-4FFE-A457-A5CFB9CEB899
    template <> inline constexpr guid guid_v<llm:OS::System::IDispatcherQueue2>{ 0xC822C647,0x30EF,0x506E,{ 0xBD,0x1E,0xA6,0x47,0xAE,0x66,0x75,0xFF } }; // C822C647-30EF-506E-BD1E-A647AE6675FF
    template <> inline constexpr guid guid_v<llm:OS::System::IDispatcherQueueController>{ 0x22F34E66,0x50DB,0x4E36,{ 0xA9,0x8D,0x61,0xC0,0x1B,0x38,0x4D,0x20 } }; // 22F34E66-50DB-4E36-A98D-61C01B384D20
    template <> inline constexpr guid guid_v<llm:OS::System::IDispatcherQueueControllerStatics>{ 0x0A6C98E0,0x5198,0x49A2,{ 0xA3,0x13,0x3F,0x70,0xD1,0xF1,0x3C,0x27 } }; // 0A6C98E0-5198-49A2-A313-3F70D1F13C27
    template <> inline constexpr guid guid_v<llm:OS::System::IDispatcherQueueShutdownStartingEventArgs>{ 0xC4724C4C,0xFF97,0x40C0,{ 0xA2,0x26,0xCC,0x0A,0xAA,0x54,0x5E,0x89 } }; // C4724C4C-FF97-40C0-A226-CC0AAA545E89
    template <> inline constexpr guid guid_v<llm:OS::System::IDispatcherQueueStatics>{ 0xA96D83D7,0x9371,0x4517,{ 0x92,0x45,0xD0,0x82,0x4A,0xC1,0x2C,0x74 } }; // A96D83D7-9371-4517-9245-D0824AC12C74
    template <> inline constexpr guid guid_v<llm:OS::System::IDispatcherQueueTimer>{ 0x5FEABB1D,0xA31C,0x4727,{ 0xB1,0xAC,0x37,0x45,0x46,0x49,0xD5,0x6A } }; // 5FEABB1D-A31C-4727-B1AC-37454649D56A
    template <> inline constexpr guid guid_v<llm:OS::System::IFolderLauncherOptions>{ 0xBB91C27D,0x6B87,0x432A,{ 0xBD,0x04,0x77,0x6C,0x6F,0x5F,0xB2,0xAB } }; // BB91C27D-6B87-432A-BD04-776C6F5FB2AB
    template <> inline constexpr guid guid_v<llm:OS::System::IKnownUserPropertiesStatics>{ 0x7755911A,0x70C5,0x48E5,{ 0xB6,0x37,0x5B,0xA3,0x44,0x1E,0x4E,0xE4 } }; // 7755911A-70C5-48E5-B637-5BA3441E4EE4
    template <> inline constexpr guid guid_v<llm:OS::System::IKnownUserPropertiesStatics2>{ 0x5B450782,0xF620,0x577E,{ 0xB1,0xB3,0xDD,0x56,0x64,0x4D,0x79,0xB1 } }; // 5B450782-F620-577E-B1B3-DD56644D79B1
    template <> inline constexpr guid guid_v<llm:OS::System::ILaunchUriResult>{ 0xEC27A8DF,0xF6D5,0x45CA,{ 0x91,0x3A,0x70,0xA4,0x0C,0x5C,0x82,0x21 } }; // EC27A8DF-F6D5-45CA-913A-70A40C5C8221
    template <> inline constexpr guid guid_v<llm:OS::System::ILauncherOptions>{ 0xBAFA21D8,0xB071,0x4CD8,{ 0x85,0x3E,0x34,0x12,0x03,0xE5,0x57,0xD3 } }; // BAFA21D8-B071-4CD8-853E-341203E557D3
    template <> inline constexpr guid guid_v<llm:OS::System::ILauncherOptions2>{ 0x3BA08EB4,0x6E40,0x4DCE,{ 0xA1,0xA3,0x2F,0x53,0x95,0x0A,0xFB,0x49 } }; // 3BA08EB4-6E40-4DCE-A1A3-2F53950AFB49
    template <> inline constexpr guid guid_v<llm:OS::System::ILauncherOptions3>{ 0xF0770655,0x4B63,0x4E3A,{ 0x91,0x07,0x4E,0x68,0x78,0x41,0x92,0x3A } }; // F0770655-4B63-4E3A-9107-4E687841923A
    template <> inline constexpr guid guid_v<llm:OS::System::ILauncherOptions4>{ 0xEF6FD10E,0xE6FB,0x4814,{ 0xA4,0x4E,0x57,0xE8,0xB9,0xD9,0xA0,0x1B } }; // EF6FD10E-E6FB-4814-A44E-57E8B9D9A01B
    template <> inline constexpr guid guid_v<llm:OS::System::ILauncherStatics>{ 0x277151C3,0x9E3E,0x42F6,{ 0x91,0xA4,0x5D,0xFD,0xEB,0x23,0x24,0x51 } }; // 277151C3-9E3E-42F6-91A4-5DFDEB232451
    template <> inline constexpr guid guid_v<llm:OS::System::ILauncherStatics2>{ 0x59BA2FBB,0x24CB,0x4C02,{ 0xA4,0xC4,0x82,0x94,0x56,0x9D,0x54,0xF1 } }; // 59BA2FBB-24CB-4C02-A4C4-8294569D54F1
    template <> inline constexpr guid guid_v<llm:OS::System::ILauncherStatics3>{ 0x234261A8,0x9DB3,0x4683,{ 0xAA,0x42,0xDC,0x6F,0x51,0xD3,0x38,0x47 } }; // 234261A8-9DB3-4683-AA42-DC6F51D33847
    template <> inline constexpr guid guid_v<llm:OS::System::ILauncherStatics4>{ 0xB9EC819F,0xB5A5,0x41C6,{ 0xB3,0xB3,0xDD,0x1B,0x31,0x78,0xBC,0xF2 } }; // B9EC819F-B5A5-41C6-B3B3-DD1B3178BCF2
    template <> inline constexpr guid guid_v<llm:OS::System::ILauncherStatics5>{ 0x5B24EF84,0xD895,0x5FEA,{ 0x91,0x53,0x1A,0xC4,0x9A,0xED,0x9B,0xA9 } }; // 5B24EF84-D895-5FEA-9153-1AC49AED9BA9
    template <> inline constexpr guid guid_v<llm:OS::System::ILauncherUIOptions>{ 0x1B25DA6E,0x8AA6,0x41E9,{ 0x82,0x51,0x41,0x65,0xF5,0x98,0x5F,0x49 } }; // 1B25DA6E-8AA6-41E9-8251-4165F5985F49
    template <> inline constexpr guid guid_v<llm:OS::System::ILauncherViewOptions>{ 0x8A9B29F1,0x7CA7,0x49DE,{ 0x9B,0xD3,0x3C,0x5B,0x71,0x84,0xF6,0x16 } }; // 8A9B29F1-7CA7-49DE-9BD3-3C5B7184F616
    template <> inline constexpr guid guid_v<llm:OS::System::IMemoryManagerStatics>{ 0x5C6C279C,0xD7CA,0x4779,{ 0x91,0x88,0x40,0x57,0x21,0x9C,0xE6,0x4C } }; // 5C6C279C-D7CA-4779-9188-4057219CE64C
    template <> inline constexpr guid guid_v<llm:OS::System::IMemoryManagerStatics2>{ 0x6EEE351F,0x6D62,0x423F,{ 0x94,0x79,0xB0,0x1F,0x9C,0x9F,0x76,0x69 } }; // 6EEE351F-6D62-423F-9479-B01F9C9F7669
    template <> inline constexpr guid guid_v<llm:OS::System::IMemoryManagerStatics3>{ 0x149B59CE,0x92AD,0x4E35,{ 0x89,0xEB,0x50,0xDF,0xB4,0xC0,0xD9,0x1C } }; // 149B59CE-92AD-4E35-89EB-50DFB4C0D91C
    template <> inline constexpr guid guid_v<llm:OS::System::IMemoryManagerStatics4>{ 0xC5A94828,0xE84E,0x4886,{ 0x8A,0x0D,0x44,0xB3,0x19,0x0E,0x3B,0x72 } }; // C5A94828-E84E-4886-8A0D-44B3190E3B72
    template <> inline constexpr guid guid_v<llm:OS::System::IProcessLauncherOptions>{ 0x3080B9CF,0xF444,0x4A83,{ 0xBE,0xAF,0xA5,0x49,0xA0,0xF3,0x22,0x9C } }; // 3080B9CF-F444-4A83-BEAF-A549A0F3229C
    template <> inline constexpr guid guid_v<llm:OS::System::IProcessLauncherResult>{ 0x544C8934,0x86D8,0x4991,{ 0x8E,0x75,0xEC,0xE8,0xA4,0x3B,0x6B,0x6D } }; // 544C8934-86D8-4991-8E75-ECE8A43B6B6D
    template <> inline constexpr guid guid_v<llm:OS::System::IProcessLauncherStatics>{ 0x33AB66E7,0x2D0E,0x448B,{ 0xA6,0xA0,0xC1,0x3C,0x38,0x36,0xD0,0x9C } }; // 33AB66E7-2D0E-448B-A6A0-C13C3836D09C
    template <> inline constexpr guid guid_v<llm:OS::System::IProcessMemoryReport>{ 0x087305A8,0x9B70,0x4782,{ 0x87,0x41,0x3A,0x98,0x2B,0x6C,0xE5,0xE4 } }; // 087305A8-9B70-4782-8741-3A982B6CE5E4
    template <> inline constexpr guid guid_v<llm:OS::System::IProtocolForResultsOperation>{ 0xD581293A,0x6DE9,0x4D28,{ 0x93,0x78,0xF8,0x67,0x82,0xE1,0x82,0xBB } }; // D581293A-6DE9-4D28-9378-F86782E182BB
    template <> inline constexpr guid guid_v<llm:OS::System::IRemoteLauncherOptions>{ 0x9E3A2788,0x2891,0x4CDF,{ 0xA2,0xD6,0x9D,0xFF,0x7D,0x02,0xE6,0x93 } }; // 9E3A2788-2891-4CDF-A2D6-9DFF7D02E693
    template <> inline constexpr guid guid_v<llm:OS::System::IRemoteLauncherStatics>{ 0xD7DB7A93,0xA30C,0x48B7,{ 0x9F,0x21,0x05,0x10,0x26,0xA4,0xE5,0x17 } }; // D7DB7A93-A30C-48B7-9F21-051026A4E517
    template <> inline constexpr guid guid_v<llm:OS::System::IShutdownManagerStatics>{ 0x72E247ED,0xDD5B,0x4D6C,{ 0xB1,0xD0,0xC5,0x7A,0x7B,0xBB,0x5F,0x94 } }; // 72E247ED-DD5B-4D6C-B1D0-C57A7BBB5F94
    template <> inline constexpr guid guid_v<llm:OS::System::IShutdownManagerStatics2>{ 0x0F69A02F,0x9C34,0x43C7,{ 0xA8,0xC3,0x70,0xB3,0x0A,0x7F,0x75,0x04 } }; // 0F69A02F-9C34-43C7-A8C3-70B30A7F7504
    template <> inline constexpr guid guid_v<llm:OS::System::ITimeZoneSettingsStatics>{ 0x9B3B2BEA,0xA101,0x41AE,{ 0x9F,0xBD,0x02,0x87,0x28,0xBA,0xB7,0x3D } }; // 9B3B2BEA-A101-41AE-9FBD-028728BAB73D
    template <> inline constexpr guid guid_v<llm:OS::System::ITimeZoneSettingsStatics2>{ 0x555C0DB8,0x39A8,0x49FA,{ 0xB4,0xF6,0xA2,0xC7,0xFC,0x28,0x42,0xEC } }; // 555C0DB8-39A8-49FA-B4F6-A2C7FC2842EC
    template <> inline constexpr guid guid_v<llm:OS::System::IUser>{ 0xDF9A26C6,0xE746,0x4BCD,{ 0xB5,0xD4,0x12,0x01,0x03,0xC4,0x20,0x9B } }; // DF9A26C6-E746-4BCD-B5D4-120103C4209B
    template <> inline constexpr guid guid_v<llm:OS::System::IUser2>{ 0x98BA5628,0xA6E3,0x518E,{ 0x89,0xD9,0xD3,0xB2,0xB1,0x99,0x1A,0x10 } }; // 98BA5628-A6E3-518E-89D9-D3B2B1991A10
    template <> inline constexpr guid guid_v<llm:OS::System::IUserAuthenticationStatusChangeDeferral>{ 0x88B59568,0xBB30,0x42FB,{ 0xA2,0x70,0xE9,0x90,0x2E,0x40,0xEF,0xA7 } }; // 88B59568-BB30-42FB-A270-E9902E40EFA7
    template <> inline constexpr guid guid_v<llm:OS::System::IUserAuthenticationStatusChangingEventArgs>{ 0x8C030F28,0xA711,0x4C1E,{ 0xAB,0x48,0x04,0x17,0x9C,0x15,0x93,0x8F } }; // 8C030F28-A711-4C1E-AB48-04179C15938F
    template <> inline constexpr guid guid_v<llm:OS::System::IUserChangedEventArgs>{ 0x086459DC,0x18C6,0x48DB,{ 0xBC,0x99,0x72,0x4F,0xB9,0x20,0x3C,0xCC } }; // 086459DC-18C6-48DB-BC99-724FB9203CCC
    template <> inline constexpr guid guid_v<llm:OS::System::IUserChangedEventArgs2>{ 0x6B2CCB44,0x6F01,0x560C,{ 0x97,0xAD,0xFC,0x7F,0x32,0xEC,0x58,0x1F } }; // 6B2CCB44-6F01-560C-97AD-FC7F32EC581F
    template <> inline constexpr guid guid_v<llm:OS::System::IUserDeviceAssociationChangedEventArgs>{ 0xBD1F6F6C,0xBB5D,0x4D7B,{ 0xA5,0xF0,0xC8,0xCD,0x11,0xA3,0x8D,0x42 } }; // BD1F6F6C-BB5D-4D7B-A5F0-C8CD11A38D42
    template <> inline constexpr guid guid_v<llm:OS::System::IUserDeviceAssociationStatics>{ 0x7E491E14,0xF85A,0x4C07,{ 0x8D,0xA9,0x7F,0xE3,0xD0,0x54,0x23,0x43 } }; // 7E491E14-F85A-4C07-8DA9-7FE3D0542343
    template <> inline constexpr guid guid_v<llm:OS::System::IUserPicker>{ 0x7D548008,0xF1E3,0x4A6C,{ 0x8D,0xDC,0xA9,0xBB,0x0F,0x48,0x8A,0xED } }; // 7D548008-F1E3-4A6C-8DDC-A9BB0F488AED
    template <> inline constexpr guid guid_v<llm:OS::System::IUserPickerStatics>{ 0xDE3290DC,0x7E73,0x4DF6,{ 0xA1,0xAE,0x4D,0x7E,0xCA,0x82,0xB4,0x0D } }; // DE3290DC-7E73-4DF6-A1AE-4D7ECA82B40D
    template <> inline constexpr guid guid_v<llm:OS::System::IUserStatics>{ 0x155EB23B,0x242A,0x45E0,{ 0xA2,0xE9,0x31,0x71,0xFC,0x6A,0x7F,0xDD } }; // 155EB23B-242A-45E0-A2E9-3171FC6A7FDD
    template <> inline constexpr guid guid_v<llm:OS::System::IUserStatics2>{ 0x74A37E11,0x2EB5,0x4487,{ 0xB0,0xD5,0x2C,0x67,0x90,0xE0,0x13,0xE9 } }; // 74A37E11-2EB5-4487-B0D5-2C6790E013E9
    template <> inline constexpr guid guid_v<llm:OS::System::IUserWatcher>{ 0x155EB23B,0x242A,0x45E0,{ 0xA2,0xE9,0x31,0x71,0xFC,0x6A,0x7F,0xBB } }; // 155EB23B-242A-45E0-A2E9-3171FC6A7FBB
    template <> inline constexpr guid guid_v<llm:OS::System::DispatcherQueueHandler>{ 0xDFA2DC9C,0x1A2D,0x4917,{ 0x98,0xF2,0x93,0x9A,0xF1,0xD6,0xE0,0xC8 } }; // DFA2DC9C-1A2D-4917-98F2-939AF1D6E0C8
    template <> struct default_interface<llm:OS::System::AppActivationResult>{ using type = llm:OS::System::IAppActivationResult; };
    template <> struct default_interface<llm:OS::System::AppDiagnosticInfo>{ using type = llm:OS::System::IAppDiagnosticInfo; };
    template <> struct default_interface<llm:OS::System::AppDiagnosticInfoWatcher>{ using type = llm:OS::System::IAppDiagnosticInfoWatcher; };
    template <> struct default_interface<llm:OS::System::AppDiagnosticInfoWatcherEventArgs>{ using type = llm:OS::System::IAppDiagnosticInfoWatcherEventArgs; };
    template <> struct default_interface<llm:OS::System::AppExecutionStateChangeResult>{ using type = llm:OS::System::IAppExecutionStateChangeResult; };
    template <> struct default_interface<llm:OS::System::AppMemoryReport>{ using type = llm:OS::System::IAppMemoryReport; };
    template <> struct default_interface<llm:OS::System::AppMemoryUsageLimitChangingEventArgs>{ using type = llm:OS::System::IAppMemoryUsageLimitChangingEventArgs; };
    template <> struct default_interface<llm:OS::System::AppResourceGroupBackgroundTaskReport>{ using type = llm:OS::System::IAppResourceGroupBackgroundTaskReport; };
    template <> struct default_interface<llm:OS::System::AppResourceGroupInfo>{ using type = llm:OS::System::IAppResourceGroupInfo; };
    template <> struct default_interface<llm:OS::System::AppResourceGroupInfoWatcher>{ using type = llm:OS::System::IAppResourceGroupInfoWatcher; };
    template <> struct default_interface<llm:OS::System::AppResourceGroupInfoWatcherEventArgs>{ using type = llm:OS::System::IAppResourceGroupInfoWatcherEventArgs; };
    template <> struct default_interface<llm:OS::System::AppResourceGroupInfoWatcherExecutionStateChangedEventArgs>{ using type = llm:OS::System::IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs; };
    template <> struct default_interface<llm:OS::System::AppResourceGroupMemoryReport>{ using type = llm:OS::System::IAppResourceGroupMemoryReport; };
    template <> struct default_interface<llm:OS::System::AppResourceGroupStateReport>{ using type = llm:OS::System::IAppResourceGroupStateReport; };
    template <> struct default_interface<llm:OS::System::AppUriHandlerHost>{ using type = llm:OS::System::IAppUriHandlerHost; };
    template <> struct default_interface<llm:OS::System::AppUriHandlerRegistration>{ using type = llm:OS::System::IAppUriHandlerRegistration; };
    template <> struct default_interface<llm:OS::System::AppUriHandlerRegistrationManager>{ using type = llm:OS::System::IAppUriHandlerRegistrationManager; };
    template <> struct default_interface<llm:OS::System::DispatcherQueue>{ using type = llm:OS::System::IDispatcherQueue; };
    template <> struct default_interface<llm:OS::System::DispatcherQueueController>{ using type = llm:OS::System::IDispatcherQueueController; };
    template <> struct default_interface<llm:OS::System::DispatcherQueueShutdownStartingEventArgs>{ using type = llm:OS::System::IDispatcherQueueShutdownStartingEventArgs; };
    template <> struct default_interface<llm:OS::System::DispatcherQueueTimer>{ using type = llm:OS::System::IDispatcherQueueTimer; };
    template <> struct default_interface<llm:OS::System::FolderLauncherOptions>{ using type = llm:OS::System::IFolderLauncherOptions; };
    template <> struct default_interface<llm:OS::System::LaunchUriResult>{ using type = llm:OS::System::ILaunchUriResult; };
    template <> struct default_interface<llm:OS::System::LauncherOptions>{ using type = llm:OS::System::ILauncherOptions; };
    template <> struct default_interface<llm:OS::System::LauncherUIOptions>{ using type = llm:OS::System::ILauncherUIOptions; };
    template <> struct default_interface<llm:OS::System::ProcessLauncherOptions>{ using type = llm:OS::System::IProcessLauncherOptions; };
    template <> struct default_interface<llm:OS::System::ProcessLauncherResult>{ using type = llm:OS::System::IProcessLauncherResult; };
    template <> struct default_interface<llm:OS::System::ProcessMemoryReport>{ using type = llm:OS::System::IProcessMemoryReport; };
    template <> struct default_interface<llm:OS::System::ProtocolForResultsOperation>{ using type = llm:OS::System::IProtocolForResultsOperation; };
    template <> struct default_interface<llm:OS::System::RemoteLauncherOptions>{ using type = llm:OS::System::IRemoteLauncherOptions; };
    template <> struct default_interface<llm:OS::System::User>{ using type = llm:OS::System::IUser; };
    template <> struct default_interface<llm:OS::System::UserAuthenticationStatusChangeDeferral>{ using type = llm:OS::System::IUserAuthenticationStatusChangeDeferral; };
    template <> struct default_interface<llm:OS::System::UserAuthenticationStatusChangingEventArgs>{ using type = llm:OS::System::IUserAuthenticationStatusChangingEventArgs; };
    template <> struct default_interface<llm:OS::System::UserChangedEventArgs>{ using type = llm:OS::System::IUserChangedEventArgs; };
    template <> struct default_interface<llm:OS::System::UserDeviceAssociationChangedEventArgs>{ using type = llm:OS::System::IUserDeviceAssociationChangedEventArgs; };
    template <> struct default_interface<llm:OS::System::UserPicker>{ using type = llm:OS::System::IUserPicker; };
    template <> struct default_interface<llm:OS::System::UserWatcher>{ using type = llm:OS::System::IUserWatcher; };
    template <> struct abi<llm:OS::System::IAppActivationResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
            virtual int32_t __stdcall get_AppResourceGroupInfo(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppDiagnosticInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AppInfo(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppDiagnosticInfo2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetResourceGroups(void**) noexcept = 0;
            virtual int32_t __stdcall CreateResourceGroupWatcher(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppDiagnosticInfo3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall LaunchAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppDiagnosticInfoStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestInfoAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppDiagnosticInfoStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWatcher(void**) noexcept = 0;
            virtual int32_t __stdcall RequestAccessAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RequestInfoForPackageAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestInfoForAppAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RequestInfoForAppUserModelId(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppDiagnosticInfoWatcher>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_Added(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Added(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Removed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Removed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_EnumerationCompleted(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_EnumerationCompleted(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Stopped(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Stopped(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall Start() noexcept = 0;
            virtual int32_t __stdcall Stop() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppDiagnosticInfoWatcherEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AppDiagnosticInfo(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppExecutionStateChangeResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppMemoryReport>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PrivateCommitUsage(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_PeakPrivateCommitUsage(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_TotalCommitUsage(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_TotalCommitLimit(uint64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppMemoryReport2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ExpectedTotalCommitLimit(uint64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppMemoryUsageLimitChangingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OldLimit(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_NewLimit(uint64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppResourceGroupBackgroundTaskReport>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TaskId(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_Trigger(void**) noexcept = 0;
            virtual int32_t __stdcall get_EntryPoint(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppResourceGroupInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_InstanceId(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall get_IsShared(bool*) noexcept = 0;
            virtual int32_t __stdcall GetBackgroundTaskReports(void**) noexcept = 0;
            virtual int32_t __stdcall GetMemoryReport(void**) noexcept = 0;
            virtual int32_t __stdcall GetProcessDiagnosticInfos(void**) noexcept = 0;
            virtual int32_t __stdcall GetStateReport(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppResourceGroupInfo2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall StartSuspendAsync(void**) noexcept = 0;
            virtual int32_t __stdcall StartResumeAsync(void**) noexcept = 0;
            virtual int32_t __stdcall StartTerminateAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppResourceGroupInfoWatcher>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_Added(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Added(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Removed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Removed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_EnumerationCompleted(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_EnumerationCompleted(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Stopped(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Stopped(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ExecutionStateChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ExecutionStateChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall Start() noexcept = 0;
            virtual int32_t __stdcall Stop() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppResourceGroupInfoWatcherEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AppDiagnosticInfos(void**) noexcept = 0;
            virtual int32_t __stdcall get_AppResourceGroupInfo(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AppDiagnosticInfos(void**) noexcept = 0;
            virtual int32_t __stdcall get_AppResourceGroupInfo(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppResourceGroupMemoryReport>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CommitUsageLimit(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_CommitUsageLevel(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PrivateCommitUsage(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_TotalCommitUsage(uint64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppResourceGroupStateReport>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ExecutionState(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_EnergyQuotaState(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppUriHandlerHost>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall put_Name(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppUriHandlerHost2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsEnabled(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppUriHandlerHostFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppUriHandlerRegistration>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_User(void**) noexcept = 0;
            virtual int32_t __stdcall GetAppAddedHostsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall SetAppAddedHostsAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppUriHandlerRegistration2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetAllHosts(void**) noexcept = 0;
            virtual int32_t __stdcall UpdateHosts(void*) noexcept = 0;
            virtual int32_t __stdcall get_PackageFamilyName(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppUriHandlerRegistrationManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_User(void**) noexcept = 0;
            virtual int32_t __stdcall TryGetRegistration(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppUriHandlerRegistrationManager2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PackageFamilyName(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppUriHandlerRegistrationManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
            virtual int32_t __stdcall GetForUser(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IAppUriHandlerRegistrationManagerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForPackage(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetForPackageForUser(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IDateTimeSettingsStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetSystemDateTime(int64_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IDispatcherQueue>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateTimer(void**) noexcept = 0;
            virtual int32_t __stdcall TryEnqueue(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall TryEnqueueWithPriority(int32_t, void*, bool*) noexcept = 0;
            virtual int32_t __stdcall add_ShutdownStarting(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ShutdownStarting(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ShutdownCompleted(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ShutdownCompleted(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IDispatcherQueue2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_HasThreadAccess(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IDispatcherQueueController>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DispatcherQueue(void**) noexcept = 0;
            virtual int32_t __stdcall ShutdownQueueAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IDispatcherQueueControllerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateOnDedicatedThread(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IDispatcherQueueShutdownStartingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IDispatcherQueueStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForCurrentThread(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IDispatcherQueueTimer>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Interval(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_Interval(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_IsRunning(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsRepeating(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsRepeating(bool) noexcept = 0;
            virtual int32_t __stdcall Start() noexcept = 0;
            virtual int32_t __stdcall Stop() noexcept = 0;
            virtual int32_t __stdcall add_Tick(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Tick(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IFolderLauncherOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ItemsToSelect(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IKnownUserPropertiesStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_FirstName(void**) noexcept = 0;
            virtual int32_t __stdcall get_LastName(void**) noexcept = 0;
            virtual int32_t __stdcall get_ProviderName(void**) noexcept = 0;
            virtual int32_t __stdcall get_AccountName(void**) noexcept = 0;
            virtual int32_t __stdcall get_GuestHost(void**) noexcept = 0;
            virtual int32_t __stdcall get_PrincipalName(void**) noexcept = 0;
            virtual int32_t __stdcall get_DomainName(void**) noexcept = 0;
            virtual int32_t __stdcall get_SessionInitiationProtocolUri(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IKnownUserPropertiesStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AgeEnforcementRegion(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::ILaunchUriResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Result(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::ILauncherOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TreatAsUntrusted(bool*) noexcept = 0;
            virtual int32_t __stdcall put_TreatAsUntrusted(bool) noexcept = 0;
            virtual int32_t __stdcall get_DisplayApplicationPicker(bool*) noexcept = 0;
            virtual int32_t __stdcall put_DisplayApplicationPicker(bool) noexcept = 0;
            virtual int32_t __stdcall get_UI(void**) noexcept = 0;
            virtual int32_t __stdcall get_PreferredApplicationPackageFamilyName(void**) noexcept = 0;
            virtual int32_t __stdcall put_PreferredApplicationPackageFamilyName(void*) noexcept = 0;
            virtual int32_t __stdcall get_PreferredApplicationDisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall put_PreferredApplicationDisplayName(void*) noexcept = 0;
            virtual int32_t __stdcall get_FallbackUri(void**) noexcept = 0;
            virtual int32_t __stdcall put_FallbackUri(void*) noexcept = 0;
            virtual int32_t __stdcall get_ContentType(void**) noexcept = 0;
            virtual int32_t __stdcall put_ContentType(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::ILauncherOptions2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TargetApplicationPackageFamilyName(void**) noexcept = 0;
            virtual int32_t __stdcall put_TargetApplicationPackageFamilyName(void*) noexcept = 0;
            virtual int32_t __stdcall get_NeighboringFilesQuery(void**) noexcept = 0;
            virtual int32_t __stdcall put_NeighboringFilesQuery(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::ILauncherOptions3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IgnoreAppUriHandlers(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IgnoreAppUriHandlers(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::ILauncherOptions4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_LimitPickerToCurrentAppAndAppUriHandlers(bool*) noexcept = 0;
            virtual int32_t __stdcall put_LimitPickerToCurrentAppAndAppUriHandlers(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::ILauncherStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall LaunchFileAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchFileWithOptionsAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchUriAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchUriWithOptionsAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::ILauncherStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall LaunchUriForResultsAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchUriForResultsWithDataAsync(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchUriWithDataAsync(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall QueryUriSupportAsync(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall QueryUriSupportWithPackageFamilyNameAsync(void*, int32_t, void*, void**) noexcept = 0;
            virtual int32_t __stdcall QueryFileSupportAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall QueryFileSupportWithPackageFamilyNameAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindUriSchemeHandlersAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindUriSchemeHandlersWithLaunchUriTypeAsync(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall FindFileHandlersAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::ILauncherStatics3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall LaunchFolderAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchFolderWithOptionsAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::ILauncherStatics4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall QueryAppUriSupportAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall QueryAppUriSupportWithPackageFamilyNameAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindAppUriHandlersAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchUriForUserAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchUriWithOptionsForUserAsync(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchUriWithDataForUserAsync(void*, void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchUriForResultsForUserAsync(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchUriForResultsWithDataForUserAsync(void*, void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::ILauncherStatics5>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall LaunchFolderPathAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchFolderPathWithOptionsAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchFolderPathForUserAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchFolderPathWithOptionsForUserAsync(void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::ILauncherUIOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_InvocationPoint(void**) noexcept = 0;
            virtual int32_t __stdcall put_InvocationPoint(void*) noexcept = 0;
            virtual int32_t __stdcall get_SelectionRect(void**) noexcept = 0;
            virtual int32_t __stdcall put_SelectionRect(void*) noexcept = 0;
            virtual int32_t __stdcall get_PreferredPlacement(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_PreferredPlacement(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::ILauncherViewOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DesiredRemainingView(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_DesiredRemainingView(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IMemoryManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AppMemoryUsage(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_AppMemoryUsageLimit(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_AppMemoryUsageLevel(int32_t*) noexcept = 0;
            virtual int32_t __stdcall add_AppMemoryUsageIncreased(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AppMemoryUsageIncreased(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_AppMemoryUsageDecreased(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AppMemoryUsageDecreased(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_AppMemoryUsageLimitChanging(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AppMemoryUsageLimitChanging(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IMemoryManagerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetAppMemoryReport(void**) noexcept = 0;
            virtual int32_t __stdcall GetProcessMemoryReport(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IMemoryManagerStatics3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TrySetAppMemoryUsageLimit(uint64_t, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IMemoryManagerStatics4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ExpectedAppMemoryUsageLimit(uint64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IProcessLauncherOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_StandardInput(void**) noexcept = 0;
            virtual int32_t __stdcall put_StandardInput(void*) noexcept = 0;
            virtual int32_t __stdcall get_StandardOutput(void**) noexcept = 0;
            virtual int32_t __stdcall put_StandardOutput(void*) noexcept = 0;
            virtual int32_t __stdcall get_StandardError(void**) noexcept = 0;
            virtual int32_t __stdcall put_StandardError(void*) noexcept = 0;
            virtual int32_t __stdcall get_WorkingDirectory(void**) noexcept = 0;
            virtual int32_t __stdcall put_WorkingDirectory(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IProcessLauncherResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ExitCode(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IProcessLauncherStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RunToCompletionAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall RunToCompletionAsyncWithOptions(void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IProcessMemoryReport>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PrivateWorkingSetUsage(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_TotalWorkingSetUsage(uint64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IProtocolForResultsOperation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ReportCompleted(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IRemoteLauncherOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FallbackUri(void**) noexcept = 0;
            virtual int32_t __stdcall put_FallbackUri(void*) noexcept = 0;
            virtual int32_t __stdcall get_PreferredAppIds(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IRemoteLauncherStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall LaunchUriAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchUriWithOptionsAsync(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchUriWithDataAsync(void*, void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IShutdownManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall BeginShutdown(int32_t, int64_t) noexcept = 0;
            virtual int32_t __stdcall CancelShutdown() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IShutdownManagerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsPowerStateSupported(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall EnterPowerState(int32_t) noexcept = 0;
            virtual int32_t __stdcall EnterPowerStateWithTimeSpan(int32_t, int64_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::ITimeZoneSettingsStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CurrentTimeZoneDisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_SupportedTimeZoneDisplayNames(void**) noexcept = 0;
            virtual int32_t __stdcall get_CanChangeTimeZone(bool*) noexcept = 0;
            virtual int32_t __stdcall ChangeTimeZoneByDisplayName(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::ITimeZoneSettingsStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall AutoUpdateTimeZoneAsync(int64_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IUser>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_NonRoamableId(void**) noexcept = 0;
            virtual int32_t __stdcall get_AuthenticationStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Type(int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetPropertyAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetPropertiesAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetPictureAsync(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IUser2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CheckUserAgeConsentGroupAsync(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IUserAuthenticationStatusChangeDeferral>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Complete() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IUserAuthenticationStatusChangingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
            virtual int32_t __stdcall get_User(void**) noexcept = 0;
            virtual int32_t __stdcall get_NewStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_CurrentStatus(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IUserChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_User(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IUserChangedEventArgs2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ChangedPropertyKinds(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IUserDeviceAssociationChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DeviceId(void**) noexcept = 0;
            virtual int32_t __stdcall get_NewUser(void**) noexcept = 0;
            virtual int32_t __stdcall get_OldUser(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IUserDeviceAssociationStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FindUserFromDeviceId(void*, void**) noexcept = 0;
            virtual int32_t __stdcall add_UserDeviceAssociationChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_UserDeviceAssociationChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IUserPicker>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AllowGuestAccounts(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AllowGuestAccounts(bool) noexcept = 0;
            virtual int32_t __stdcall get_SuggestedSelectedUser(void**) noexcept = 0;
            virtual int32_t __stdcall put_SuggestedSelectedUser(void*) noexcept = 0;
            virtual int32_t __stdcall PickSingleUserAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IUserPickerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsSupported(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IUserStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWatcher(void**) noexcept = 0;
            virtual int32_t __stdcall FindAllAsync(void**) noexcept = 0;
            virtual int32_t __stdcall FindAllAsyncByType(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall FindAllAsyncByTypeAndStatus(int32_t, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetFromId(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IUserStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::IUserWatcher>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall Start() noexcept = 0;
            virtual int32_t __stdcall Stop() noexcept = 0;
            virtual int32_t __stdcall add_Added(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Added(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Removed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Removed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Updated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Updated(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_AuthenticationStatusChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AuthenticationStatusChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_AuthenticationStatusChanging(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AuthenticationStatusChanging(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_EnumerationCompleted(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_EnumerationCompleted(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Stopped(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Stopped(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::DispatcherQueueHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke() noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_System_IAppActivationResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::AppResourceGroupInfo) AppResourceGroupInfo() const;
    };
    template <> struct consume<llm:OS::System::IAppActivationResult>
    {
        template <typename D> using type = consume_Windows_System_IAppActivationResult<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppDiagnosticInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::ApplicationModel::AppInfo) AppInfo() const;
    };
    template <> struct consume<llm:OS::System::IAppDiagnosticInfo>
    {
        template <typename D> using type = consume_Windows_System_IAppDiagnosticInfo<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppDiagnosticInfo2
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::System::AppResourceGroupInfo>) GetResourceGroups() const;
        LLM_IMPL_AUTO(llm:OS::System::AppResourceGroupInfoWatcher) CreateResourceGroupWatcher() const;
    };
    template <> struct consume<llm:OS::System::IAppDiagnosticInfo2>
    {
        template <typename D> using type = consume_Windows_System_IAppDiagnosticInfo2<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppDiagnosticInfo3
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::AppActivationResult>) LaunchAsync() const;
    };
    template <> struct consume<llm:OS::System::IAppDiagnosticInfo3>
    {
        template <typename D> using type = consume_Windows_System_IAppDiagnosticInfo3<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppDiagnosticInfoStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVector<llm:OS::System::AppDiagnosticInfo>>) RequestInfoAsync() const;
    };
    template <> struct consume<llm:OS::System::IAppDiagnosticInfoStatics>
    {
        template <typename D> using type = consume_Windows_System_IAppDiagnosticInfoStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppDiagnosticInfoStatics2
    {
        LLM_IMPL_AUTO(llm:OS::System::AppDiagnosticInfoWatcher) CreateWatcher() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::DiagnosticAccessStatus>) RequestAccessAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVector<llm:OS::System::AppDiagnosticInfo>>) RequestInfoForPackageAsync(param::hstring const& packageFamilyName) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVector<llm:OS::System::AppDiagnosticInfo>>) RequestInfoForAppAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVector<llm:OS::System::AppDiagnosticInfo>>) RequestInfoForAppAsync(param::hstring const& appUserModelId) const;
    };
    template <> struct consume<llm:OS::System::IAppDiagnosticInfoStatics2>
    {
        template <typename D> using type = consume_Windows_System_IAppDiagnosticInfoStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppDiagnosticInfoWatcher
    {
        LLM_IMPL_AUTO(llm::event_token) Added(llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppDiagnosticInfoWatcher, llm:OS::System::AppDiagnosticInfoWatcherEventArgs> const& handler) const;
        using Added_revoker = impl::event_revoker<llm:OS::System::IAppDiagnosticInfoWatcher, &impl::abi_t<llm:OS::System::IAppDiagnosticInfoWatcher>::remove_Added>;
        [[nodiscard]] Added_revoker Added(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppDiagnosticInfoWatcher, llm:OS::System::AppDiagnosticInfoWatcherEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Added(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Removed(llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppDiagnosticInfoWatcher, llm:OS::System::AppDiagnosticInfoWatcherEventArgs> const& handler) const;
        using Removed_revoker = impl::event_revoker<llm:OS::System::IAppDiagnosticInfoWatcher, &impl::abi_t<llm:OS::System::IAppDiagnosticInfoWatcher>::remove_Removed>;
        [[nodiscard]] Removed_revoker Removed(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppDiagnosticInfoWatcher, llm:OS::System::AppDiagnosticInfoWatcherEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Removed(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) EnumerationCompleted(llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppDiagnosticInfoWatcher, llm:OS::Foundation::IInspectable> const& handler) const;
        using EnumerationCompleted_revoker = impl::event_revoker<llm:OS::System::IAppDiagnosticInfoWatcher, &impl::abi_t<llm:OS::System::IAppDiagnosticInfoWatcher>::remove_EnumerationCompleted>;
        [[nodiscard]] EnumerationCompleted_revoker EnumerationCompleted(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppDiagnosticInfoWatcher, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) EnumerationCompleted(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Stopped(llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppDiagnosticInfoWatcher, llm:OS::Foundation::IInspectable> const& handler) const;
        using Stopped_revoker = impl::event_revoker<llm:OS::System::IAppDiagnosticInfoWatcher, &impl::abi_t<llm:OS::System::IAppDiagnosticInfoWatcher>::remove_Stopped>;
        [[nodiscard]] Stopped_revoker Stopped(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppDiagnosticInfoWatcher, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Stopped(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::AppDiagnosticInfoWatcherStatus) Status() const;
        LLM_IMPL_AUTO(void) Start() const;
        LLM_IMPL_AUTO(void) Stop() const;
    };
    template <> struct consume<llm:OS::System::IAppDiagnosticInfoWatcher>
    {
        template <typename D> using type = consume_Windows_System_IAppDiagnosticInfoWatcher<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppDiagnosticInfoWatcherEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::AppDiagnosticInfo) AppDiagnosticInfo() const;
    };
    template <> struct consume<llm:OS::System::IAppDiagnosticInfoWatcherEventArgs>
    {
        template <typename D> using type = consume_Windows_System_IAppDiagnosticInfoWatcherEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppExecutionStateChangeResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
    };
    template <> struct consume<llm:OS::System::IAppExecutionStateChangeResult>
    {
        template <typename D> using type = consume_Windows_System_IAppExecutionStateChangeResult<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppMemoryReport
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) PrivateCommitUsage() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) PeakPrivateCommitUsage() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) TotalCommitUsage() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) TotalCommitLimit() const;
    };
    template <> struct consume<llm:OS::System::IAppMemoryReport>
    {
        template <typename D> using type = consume_Windows_System_IAppMemoryReport<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppMemoryReport2
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) ExpectedTotalCommitLimit() const;
    };
    template <> struct consume<llm:OS::System::IAppMemoryReport2>
    {
        template <typename D> using type = consume_Windows_System_IAppMemoryReport2<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppMemoryUsageLimitChangingEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) OldLimit() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) NewLimit() const;
    };
    template <> struct consume<llm:OS::System::IAppMemoryUsageLimitChangingEventArgs>
    {
        template <typename D> using type = consume_Windows_System_IAppMemoryUsageLimitChangingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppResourceGroupBackgroundTaskReport
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) TaskId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Trigger() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) EntryPoint() const;
    };
    template <> struct consume<llm:OS::System::IAppResourceGroupBackgroundTaskReport>
    {
        template <typename D> using type = consume_Windows_System_IAppResourceGroupBackgroundTaskReport<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppResourceGroupInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) InstanceId() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsShared() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::System::AppResourceGroupBackgroundTaskReport>) GetBackgroundTaskReports() const;
        LLM_IMPL_AUTO(llm:OS::System::AppResourceGroupMemoryReport) GetMemoryReport() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::System::Diagnostics::ProcessDiagnosticInfo>) GetProcessDiagnosticInfos() const;
        LLM_IMPL_AUTO(llm:OS::System::AppResourceGroupStateReport) GetStateReport() const;
    };
    template <> struct consume<llm:OS::System::IAppResourceGroupInfo>
    {
        template <typename D> using type = consume_Windows_System_IAppResourceGroupInfo<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppResourceGroupInfo2
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::AppExecutionStateChangeResult>) StartSuspendAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::AppExecutionStateChangeResult>) StartResumeAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::AppExecutionStateChangeResult>) StartTerminateAsync() const;
    };
    template <> struct consume<llm:OS::System::IAppResourceGroupInfo2>
    {
        template <typename D> using type = consume_Windows_System_IAppResourceGroupInfo2<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppResourceGroupInfoWatcher
    {
        LLM_IMPL_AUTO(llm::event_token) Added(llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppResourceGroupInfoWatcher, llm:OS::System::AppResourceGroupInfoWatcherEventArgs> const& handler) const;
        using Added_revoker = impl::event_revoker<llm:OS::System::IAppResourceGroupInfoWatcher, &impl::abi_t<llm:OS::System::IAppResourceGroupInfoWatcher>::remove_Added>;
        [[nodiscard]] Added_revoker Added(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppResourceGroupInfoWatcher, llm:OS::System::AppResourceGroupInfoWatcherEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Added(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Removed(llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppResourceGroupInfoWatcher, llm:OS::System::AppResourceGroupInfoWatcherEventArgs> const& handler) const;
        using Removed_revoker = impl::event_revoker<llm:OS::System::IAppResourceGroupInfoWatcher, &impl::abi_t<llm:OS::System::IAppResourceGroupInfoWatcher>::remove_Removed>;
        [[nodiscard]] Removed_revoker Removed(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppResourceGroupInfoWatcher, llm:OS::System::AppResourceGroupInfoWatcherEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Removed(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) EnumerationCompleted(llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppResourceGroupInfoWatcher, llm:OS::Foundation::IInspectable> const& handler) const;
        using EnumerationCompleted_revoker = impl::event_revoker<llm:OS::System::IAppResourceGroupInfoWatcher, &impl::abi_t<llm:OS::System::IAppResourceGroupInfoWatcher>::remove_EnumerationCompleted>;
        [[nodiscard]] EnumerationCompleted_revoker EnumerationCompleted(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppResourceGroupInfoWatcher, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) EnumerationCompleted(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Stopped(llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppResourceGroupInfoWatcher, llm:OS::Foundation::IInspectable> const& handler) const;
        using Stopped_revoker = impl::event_revoker<llm:OS::System::IAppResourceGroupInfoWatcher, &impl::abi_t<llm:OS::System::IAppResourceGroupInfoWatcher>::remove_Stopped>;
        [[nodiscard]] Stopped_revoker Stopped(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppResourceGroupInfoWatcher, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Stopped(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ExecutionStateChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppResourceGroupInfoWatcher, llm:OS::System::AppResourceGroupInfoWatcherExecutionStateChangedEventArgs> const& handler) const;
        using ExecutionStateChanged_revoker = impl::event_revoker<llm:OS::System::IAppResourceGroupInfoWatcher, &impl::abi_t<llm:OS::System::IAppResourceGroupInfoWatcher>::remove_ExecutionStateChanged>;
        [[nodiscard]] ExecutionStateChanged_revoker ExecutionStateChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::AppResourceGroupInfoWatcher, llm:OS::System::AppResourceGroupInfoWatcherExecutionStateChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) ExecutionStateChanged(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::AppResourceGroupInfoWatcherStatus) Status() const;
        LLM_IMPL_AUTO(void) Start() const;
        LLM_IMPL_AUTO(void) Stop() const;
    };
    template <> struct consume<llm:OS::System::IAppResourceGroupInfoWatcher>
    {
        template <typename D> using type = consume_Windows_System_IAppResourceGroupInfoWatcher<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppResourceGroupInfoWatcherEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::System::AppDiagnosticInfo>) AppDiagnosticInfos() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::AppResourceGroupInfo) AppResourceGroupInfo() const;
    };
    template <> struct consume<llm:OS::System::IAppResourceGroupInfoWatcherEventArgs>
    {
        template <typename D> using type = consume_Windows_System_IAppResourceGroupInfoWatcherEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::System::AppDiagnosticInfo>) AppDiagnosticInfos() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::AppResourceGroupInfo) AppResourceGroupInfo() const;
    };
    template <> struct consume<llm:OS::System::IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_System_IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppResourceGroupMemoryReport
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) CommitUsageLimit() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::AppMemoryUsageLevel) CommitUsageLevel() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) PrivateCommitUsage() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) TotalCommitUsage() const;
    };
    template <> struct consume<llm:OS::System::IAppResourceGroupMemoryReport>
    {
        template <typename D> using type = consume_Windows_System_IAppResourceGroupMemoryReport<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppResourceGroupStateReport
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::AppResourceGroupExecutionState) ExecutionState() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::AppResourceGroupEnergyQuotaState) EnergyQuotaState() const;
    };
    template <> struct consume<llm:OS::System::IAppResourceGroupStateReport>
    {
        template <typename D> using type = consume_Windows_System_IAppResourceGroupStateReport<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppUriHandlerHost
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        LLM_IMPL_AUTO(void) Name(param::hstring const& value) const;
    };
    template <> struct consume<llm:OS::System::IAppUriHandlerHost>
    {
        template <typename D> using type = consume_Windows_System_IAppUriHandlerHost<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppUriHandlerHost2
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsEnabled() const;
        LLM_IMPL_AUTO(void) IsEnabled(bool value) const;
    };
    template <> struct consume<llm:OS::System::IAppUriHandlerHost2>
    {
        template <typename D> using type = consume_Windows_System_IAppUriHandlerHost2<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppUriHandlerHostFactory
    {
        LLM_IMPL_AUTO(llm:OS::System::AppUriHandlerHost) CreateInstance(param::hstring const& name) const;
    };
    template <> struct consume<llm:OS::System::IAppUriHandlerHostFactory>
    {
        template <typename D> using type = consume_Windows_System_IAppUriHandlerHostFactory<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppUriHandlerRegistration
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::User) User() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVector<llm:OS::System::AppUriHandlerHost>>) GetAppAddedHostsAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetAppAddedHostsAsync(param::async_iterable<llm:OS::System::AppUriHandlerHost> const& hosts) const;
    };
    template <> struct consume<llm:OS::System::IAppUriHandlerRegistration>
    {
        template <typename D> using type = consume_Windows_System_IAppUriHandlerRegistration<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppUriHandlerRegistration2
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::System::AppUriHandlerHost>) GetAllHosts() const;
        LLM_IMPL_AUTO(void) UpdateHosts(param::iterable<llm:OS::System::AppUriHandlerHost> const& hosts) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PackageFamilyName() const;
    };
    template <> struct consume<llm:OS::System::IAppUriHandlerRegistration2>
    {
        template <typename D> using type = consume_Windows_System_IAppUriHandlerRegistration2<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppUriHandlerRegistrationManager
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::User) User() const;
        LLM_IMPL_AUTO(llm:OS::System::AppUriHandlerRegistration) TryGetRegistration(param::hstring const& name) const;
    };
    template <> struct consume<llm:OS::System::IAppUriHandlerRegistrationManager>
    {
        template <typename D> using type = consume_Windows_System_IAppUriHandlerRegistrationManager<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppUriHandlerRegistrationManager2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PackageFamilyName() const;
    };
    template <> struct consume<llm:OS::System::IAppUriHandlerRegistrationManager2>
    {
        template <typename D> using type = consume_Windows_System_IAppUriHandlerRegistrationManager2<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppUriHandlerRegistrationManagerStatics
    {
        LLM_IMPL_AUTO(llm:OS::System::AppUriHandlerRegistrationManager) GetDefault() const;
        LLM_IMPL_AUTO(llm:OS::System::AppUriHandlerRegistrationManager) GetForUser(llm:OS::System::User const& user) const;
    };
    template <> struct consume<llm:OS::System::IAppUriHandlerRegistrationManagerStatics>
    {
        template <typename D> using type = consume_Windows_System_IAppUriHandlerRegistrationManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_IAppUriHandlerRegistrationManagerStatics2
    {
        LLM_IMPL_AUTO(llm:OS::System::AppUriHandlerRegistrationManager) GetForPackage(param::hstring const& packageFamilyName) const;
        LLM_IMPL_AUTO(llm:OS::System::AppUriHandlerRegistrationManager) GetForPackageForUser(param::hstring const& packageFamilyName, llm:OS::System::User const& user) const;
    };
    template <> struct consume<llm:OS::System::IAppUriHandlerRegistrationManagerStatics2>
    {
        template <typename D> using type = consume_Windows_System_IAppUriHandlerRegistrationManagerStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_System_IDateTimeSettingsStatics
    {
        LLM_IMPL_AUTO(void) SetSystemDateTime(llm:OS::Foundation::DateTime const& utcDateTime) const;
    };
    template <> struct consume<llm:OS::System::IDateTimeSettingsStatics>
    {
        template <typename D> using type = consume_Windows_System_IDateTimeSettingsStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_IDispatcherQueue
    {
        LLM_IMPL_AUTO(llm:OS::System::DispatcherQueueTimer) CreateTimer() const;
        LLM_IMPL_AUTO(bool) TryEnqueue(llm:OS::System::DispatcherQueueHandler const& callback) const;
        LLM_IMPL_AUTO(bool) TryEnqueue(llm:OS::System::DispatcherQueuePriority const& priority, llm:OS::System::DispatcherQueueHandler const& callback) const;
        LLM_IMPL_AUTO(llm::event_token) ShutdownStarting(llm:OS::Foundation::TypedEventHandler<llm:OS::System::DispatcherQueue, llm:OS::System::DispatcherQueueShutdownStartingEventArgs> const& handler) const;
        using ShutdownStarting_revoker = impl::event_revoker<llm:OS::System::IDispatcherQueue, &impl::abi_t<llm:OS::System::IDispatcherQueue>::remove_ShutdownStarting>;
        [[nodiscard]] ShutdownStarting_revoker ShutdownStarting(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::DispatcherQueue, llm:OS::System::DispatcherQueueShutdownStartingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) ShutdownStarting(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ShutdownCompleted(llm:OS::Foundation::TypedEventHandler<llm:OS::System::DispatcherQueue, llm:OS::Foundation::IInspectable> const& handler) const;
        using ShutdownCompleted_revoker = impl::event_revoker<llm:OS::System::IDispatcherQueue, &impl::abi_t<llm:OS::System::IDispatcherQueue>::remove_ShutdownCompleted>;
        [[nodiscard]] ShutdownCompleted_revoker ShutdownCompleted(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::DispatcherQueue, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) ShutdownCompleted(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::System::IDispatcherQueue>
    {
        template <typename D> using type = consume_Windows_System_IDispatcherQueue<D>;
    };
    template <typename D>
    struct consume_Windows_System_IDispatcherQueue2
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) HasThreadAccess() const;
    };
    template <> struct consume<llm:OS::System::IDispatcherQueue2>
    {
        template <typename D> using type = consume_Windows_System_IDispatcherQueue2<D>;
    };
    template <typename D>
    struct consume_Windows_System_IDispatcherQueueController
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::DispatcherQueue) DispatcherQueue() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) ShutdownQueueAsync() const;
    };
    template <> struct consume<llm:OS::System::IDispatcherQueueController>
    {
        template <typename D> using type = consume_Windows_System_IDispatcherQueueController<D>;
    };
    template <typename D>
    struct consume_Windows_System_IDispatcherQueueControllerStatics
    {
        LLM_IMPL_AUTO(llm:OS::System::DispatcherQueueController) CreateOnDedicatedThread() const;
    };
    template <> struct consume<llm:OS::System::IDispatcherQueueControllerStatics>
    {
        template <typename D> using type = consume_Windows_System_IDispatcherQueueControllerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_IDispatcherQueueShutdownStartingEventArgs
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm:OS::System::IDispatcherQueueShutdownStartingEventArgs>
    {
        template <typename D> using type = consume_Windows_System_IDispatcherQueueShutdownStartingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_System_IDispatcherQueueStatics
    {
        LLM_IMPL_AUTO(llm:OS::System::DispatcherQueue) GetForCurrentThread() const;
    };
    template <> struct consume<llm:OS::System::IDispatcherQueueStatics>
    {
        template <typename D> using type = consume_Windows_System_IDispatcherQueueStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_IDispatcherQueueTimer
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) Interval() const;
        LLM_IMPL_AUTO(void) Interval(llm:OS::Foundation::TimeSpan const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsRunning() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsRepeating() const;
        LLM_IMPL_AUTO(void) IsRepeating(bool value) const;
        LLM_IMPL_AUTO(void) Start() const;
        LLM_IMPL_AUTO(void) Stop() const;
        LLM_IMPL_AUTO(llm::event_token) Tick(llm:OS::Foundation::TypedEventHandler<llm:OS::System::DispatcherQueueTimer, llm:OS::Foundation::IInspectable> const& handler) const;
        using Tick_revoker = impl::event_revoker<llm:OS::System::IDispatcherQueueTimer, &impl::abi_t<llm:OS::System::IDispatcherQueueTimer>::remove_Tick>;
        [[nodiscard]] Tick_revoker Tick(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::DispatcherQueueTimer, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Tick(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::System::IDispatcherQueueTimer>
    {
        template <typename D> using type = consume_Windows_System_IDispatcherQueueTimer<D>;
    };
    template <typename D>
    struct consume_Windows_System_IFolderLauncherOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::Storage::IStorageItem>) ItemsToSelect() const;
    };
    template <> struct consume<llm:OS::System::IFolderLauncherOptions>
    {
        template <typename D> using type = consume_Windows_System_IFolderLauncherOptions<D>;
    };
    template <typename D>
    struct consume_Windows_System_IKnownUserPropertiesStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) FirstName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) LastName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ProviderName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AccountName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) GuestHost() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PrincipalName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DomainName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SessionInitiationProtocolUri() const;
    };
    template <> struct consume<llm:OS::System::IKnownUserPropertiesStatics>
    {
        template <typename D> using type = consume_Windows_System_IKnownUserPropertiesStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_IKnownUserPropertiesStatics2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AgeEnforcementRegion() const;
    };
    template <> struct consume<llm:OS::System::IKnownUserPropertiesStatics2>
    {
        template <typename D> using type = consume_Windows_System_IKnownUserPropertiesStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_System_ILaunchUriResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::LaunchUriStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::ValueSet) Result() const;
    };
    template <> struct consume<llm:OS::System::ILaunchUriResult>
    {
        template <typename D> using type = consume_Windows_System_ILaunchUriResult<D>;
    };
    template <typename D>
    struct consume_Windows_System_ILauncherOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) TreatAsUntrusted() const;
        LLM_IMPL_AUTO(void) TreatAsUntrusted(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) DisplayApplicationPicker() const;
        LLM_IMPL_AUTO(void) DisplayApplicationPicker(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::LauncherUIOptions) UI() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PreferredApplicationPackageFamilyName() const;
        LLM_IMPL_AUTO(void) PreferredApplicationPackageFamilyName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PreferredApplicationDisplayName() const;
        LLM_IMPL_AUTO(void) PreferredApplicationDisplayName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Uri) FallbackUri() const;
        LLM_IMPL_AUTO(void) FallbackUri(llm:OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ContentType() const;
        LLM_IMPL_AUTO(void) ContentType(param::hstring const& value) const;
    };
    template <> struct consume<llm:OS::System::ILauncherOptions>
    {
        template <typename D> using type = consume_Windows_System_ILauncherOptions<D>;
    };
    template <typename D>
    struct consume_Windows_System_ILauncherOptions2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) TargetApplicationPackageFamilyName() const;
        LLM_IMPL_AUTO(void) TargetApplicationPackageFamilyName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Search::StorageFileQueryResult) NeighboringFilesQuery() const;
        LLM_IMPL_AUTO(void) NeighboringFilesQuery(llm:OS::Storage::Search::StorageFileQueryResult const& value) const;
    };
    template <> struct consume<llm:OS::System::ILauncherOptions2>
    {
        template <typename D> using type = consume_Windows_System_ILauncherOptions2<D>;
    };
    template <typename D>
    struct consume_Windows_System_ILauncherOptions3
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IgnoreAppUriHandlers() const;
        LLM_IMPL_AUTO(void) IgnoreAppUriHandlers(bool value) const;
    };
    template <> struct consume<llm:OS::System::ILauncherOptions3>
    {
        template <typename D> using type = consume_Windows_System_ILauncherOptions3<D>;
    };
    template <typename D>
    struct consume_Windows_System_ILauncherOptions4
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) LimitPickerToCurrentAppAndAppUriHandlers() const;
        LLM_IMPL_AUTO(void) LimitPickerToCurrentAppAndAppUriHandlers(bool value) const;
    };
    template <> struct consume<llm:OS::System::ILauncherOptions4>
    {
        template <typename D> using type = consume_Windows_System_ILauncherOptions4<D>;
    };
    template <typename D>
    struct consume_Windows_System_ILauncherStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) LaunchFileAsync(llm:OS::Storage::IStorageFile const& file) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) LaunchFileAsync(llm:OS::Storage::IStorageFile const& file, llm:OS::System::LauncherOptions const& options) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) LaunchUriAsync(llm:OS::Foundation::Uri const& uri) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) LaunchUriAsync(llm:OS::Foundation::Uri const& uri, llm:OS::System::LauncherOptions const& options) const;
    };
    template <> struct consume<llm:OS::System::ILauncherStatics>
    {
        template <typename D> using type = consume_Windows_System_ILauncherStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_ILauncherStatics2
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::LaunchUriResult>) LaunchUriForResultsAsync(llm:OS::Foundation::Uri const& uri, llm:OS::System::LauncherOptions const& options) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::LaunchUriResult>) LaunchUriForResultsAsync(llm:OS::Foundation::Uri const& uri, llm:OS::System::LauncherOptions const& options, llm:OS::Foundation::Collections::ValueSet const& inputData) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) LaunchUriAsync(llm:OS::Foundation::Uri const& uri, llm:OS::System::LauncherOptions const& options, llm:OS::Foundation::Collections::ValueSet const& inputData) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::LaunchQuerySupportStatus>) QueryUriSupportAsync(llm:OS::Foundation::Uri const& uri, llm:OS::System::LaunchQuerySupportType const& launchQuerySupportType) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::LaunchQuerySupportStatus>) QueryUriSupportAsync(llm:OS::Foundation::Uri const& uri, llm:OS::System::LaunchQuerySupportType const& launchQuerySupportType, param::hstring const& packageFamilyName) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::LaunchQuerySupportStatus>) QueryFileSupportAsync(llm:OS::Storage::StorageFile const& file) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::LaunchQuerySupportStatus>) QueryFileSupportAsync(llm:OS::Storage::StorageFile const& file, param::hstring const& packageFamilyName) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::ApplicationModel::AppInfo>>) FindUriSchemeHandlersAsync(param::hstring const& scheme) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::ApplicationModel::AppInfo>>) FindUriSchemeHandlersAsync(param::hstring const& scheme, llm:OS::System::LaunchQuerySupportType const& launchQuerySupportType) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::ApplicationModel::AppInfo>>) FindFileHandlersAsync(param::hstring const& extension) const;
    };
    template <> struct consume<llm:OS::System::ILauncherStatics2>
    {
        template <typename D> using type = consume_Windows_System_ILauncherStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_System_ILauncherStatics3
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) LaunchFolderAsync(llm:OS::Storage::IStorageFolder const& folder) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) LaunchFolderAsync(llm:OS::Storage::IStorageFolder const& folder, llm:OS::System::FolderLauncherOptions const& options) const;
    };
    template <> struct consume<llm:OS::System::ILauncherStatics3>
    {
        template <typename D> using type = consume_Windows_System_ILauncherStatics3<D>;
    };
    template <typename D>
    struct consume_Windows_System_ILauncherStatics4
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::LaunchQuerySupportStatus>) QueryAppUriSupportAsync(llm:OS::Foundation::Uri const& uri) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::LaunchQuerySupportStatus>) QueryAppUriSupportAsync(llm:OS::Foundation::Uri const& uri, param::hstring const& packageFamilyName) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::ApplicationModel::AppInfo>>) FindAppUriHandlersAsync(llm:OS::Foundation::Uri const& uri) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::LaunchUriStatus>) LaunchUriForUserAsync(llm:OS::System::User const& user, llm:OS::Foundation::Uri const& uri) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::LaunchUriStatus>) LaunchUriForUserAsync(llm:OS::System::User const& user, llm:OS::Foundation::Uri const& uri, llm:OS::System::LauncherOptions const& options) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::LaunchUriStatus>) LaunchUriForUserAsync(llm:OS::System::User const& user, llm:OS::Foundation::Uri const& uri, llm:OS::System::LauncherOptions const& options, llm:OS::Foundation::Collections::ValueSet const& inputData) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::LaunchUriResult>) LaunchUriForResultsForUserAsync(llm:OS::System::User const& user, llm:OS::Foundation::Uri const& uri, llm:OS::System::LauncherOptions const& options) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::LaunchUriResult>) LaunchUriForResultsForUserAsync(llm:OS::System::User const& user, llm:OS::Foundation::Uri const& uri, llm:OS::System::LauncherOptions const& options, llm:OS::Foundation::Collections::ValueSet const& inputData) const;
    };
    template <> struct consume<llm:OS::System::ILauncherStatics4>
    {
        template <typename D> using type = consume_Windows_System_ILauncherStatics4<D>;
    };
    template <typename D>
    struct consume_Windows_System_ILauncherStatics5
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) LaunchFolderPathAsync(param::hstring const& path) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) LaunchFolderPathAsync(param::hstring const& path, llm:OS::System::FolderLauncherOptions const& options) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) LaunchFolderPathForUserAsync(llm:OS::System::User const& user, param::hstring const& path) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) LaunchFolderPathForUserAsync(llm:OS::System::User const& user, param::hstring const& path, llm:OS::System::FolderLauncherOptions const& options) const;
    };
    template <> struct consume<llm:OS::System::ILauncherStatics5>
    {
        template <typename D> using type = consume_Windows_System_ILauncherStatics5<D>;
    };
    template <typename D>
    struct consume_Windows_System_ILauncherUIOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<llm:OS::Foundation::Point>) InvocationPoint() const;
        LLM_IMPL_AUTO(void) InvocationPoint(llm:OS::Foundation::IReference<llm:OS::Foundation::Point> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<llm:OS::Foundation::Rect>) SelectionRect() const;
        LLM_IMPL_AUTO(void) SelectionRect(llm:OS::Foundation::IReference<llm:OS::Foundation::Rect> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Popups::Placement) PreferredPlacement() const;
        LLM_IMPL_AUTO(void) PreferredPlacement(llm:OS::UI::Popups::Placement const& value) const;
    };
    template <> struct consume<llm:OS::System::ILauncherUIOptions>
    {
        template <typename D> using type = consume_Windows_System_ILauncherUIOptions<D>;
    };
    template <typename D>
    struct consume_Windows_System_ILauncherViewOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::ViewManagement::ViewSizePreference) DesiredRemainingView() const;
        LLM_IMPL_AUTO(void) DesiredRemainingView(llm:OS::UI::ViewManagement::ViewSizePreference const& value) const;
    };
    template <> struct consume<llm:OS::System::ILauncherViewOptions>
    {
        template <typename D> using type = consume_Windows_System_ILauncherViewOptions<D>;
    };
    template <typename D>
    struct consume_Windows_System_IMemoryManagerStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) AppMemoryUsage() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) AppMemoryUsageLimit() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::AppMemoryUsageLevel) AppMemoryUsageLevel() const;
        LLM_IMPL_AUTO(llm::event_token) AppMemoryUsageIncreased(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        using AppMemoryUsageIncreased_revoker = impl::event_revoker<llm:OS::System::IMemoryManagerStatics, &impl::abi_t<llm:OS::System::IMemoryManagerStatics>::remove_AppMemoryUsageIncreased>;
        [[nodiscard]] AppMemoryUsageIncreased_revoker AppMemoryUsageIncreased(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) AppMemoryUsageIncreased(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) AppMemoryUsageDecreased(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        using AppMemoryUsageDecreased_revoker = impl::event_revoker<llm:OS::System::IMemoryManagerStatics, &impl::abi_t<llm:OS::System::IMemoryManagerStatics>::remove_AppMemoryUsageDecreased>;
        [[nodiscard]] AppMemoryUsageDecreased_revoker AppMemoryUsageDecreased(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) AppMemoryUsageDecreased(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) AppMemoryUsageLimitChanging(llm:OS::Foundation::EventHandler<llm:OS::System::AppMemoryUsageLimitChangingEventArgs> const& handler) const;
        using AppMemoryUsageLimitChanging_revoker = impl::event_revoker<llm:OS::System::IMemoryManagerStatics, &impl::abi_t<llm:OS::System::IMemoryManagerStatics>::remove_AppMemoryUsageLimitChanging>;
        [[nodiscard]] AppMemoryUsageLimitChanging_revoker AppMemoryUsageLimitChanging(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::System::AppMemoryUsageLimitChangingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) AppMemoryUsageLimitChanging(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::System::IMemoryManagerStatics>
    {
        template <typename D> using type = consume_Windows_System_IMemoryManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_IMemoryManagerStatics2
    {
        LLM_IMPL_AUTO(llm:OS::System::AppMemoryReport) GetAppMemoryReport() const;
        LLM_IMPL_AUTO(llm:OS::System::ProcessMemoryReport) GetProcessMemoryReport() const;
    };
    template <> struct consume<llm:OS::System::IMemoryManagerStatics2>
    {
        template <typename D> using type = consume_Windows_System_IMemoryManagerStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_System_IMemoryManagerStatics3
    {
        LLM_IMPL_AUTO(bool) TrySetAppMemoryUsageLimit(uint64_t value) const;
    };
    template <> struct consume<llm:OS::System::IMemoryManagerStatics3>
    {
        template <typename D> using type = consume_Windows_System_IMemoryManagerStatics3<D>;
    };
    template <typename D>
    struct consume_Windows_System_IMemoryManagerStatics4
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) ExpectedAppMemoryUsageLimit() const;
    };
    template <> struct consume<llm:OS::System::IMemoryManagerStatics4>
    {
        template <typename D> using type = consume_Windows_System_IMemoryManagerStatics4<D>;
    };
    template <typename D>
    struct consume_Windows_System_IProcessLauncherOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IInputStream) StandardInput() const;
        LLM_IMPL_AUTO(void) StandardInput(llm:OS::Storage::Streams::IInputStream const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IOutputStream) StandardOutput() const;
        LLM_IMPL_AUTO(void) StandardOutput(llm:OS::Storage::Streams::IOutputStream const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IOutputStream) StandardError() const;
        LLM_IMPL_AUTO(void) StandardError(llm:OS::Storage::Streams::IOutputStream const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) WorkingDirectory() const;
        LLM_IMPL_AUTO(void) WorkingDirectory(param::hstring const& value) const;
    };
    template <> struct consume<llm:OS::System::IProcessLauncherOptions>
    {
        template <typename D> using type = consume_Windows_System_IProcessLauncherOptions<D>;
    };
    template <typename D>
    struct consume_Windows_System_IProcessLauncherResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) ExitCode() const;
    };
    template <> struct consume<llm:OS::System::IProcessLauncherResult>
    {
        template <typename D> using type = consume_Windows_System_IProcessLauncherResult<D>;
    };
    template <typename D>
    struct consume_Windows_System_IProcessLauncherStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::ProcessLauncherResult>) RunToCompletionAsync(param::hstring const& fileName, param::hstring const& args) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::ProcessLauncherResult>) RunToCompletionAsync(param::hstring const& fileName, param::hstring const& args, llm:OS::System::ProcessLauncherOptions const& options) const;
    };
    template <> struct consume<llm:OS::System::IProcessLauncherStatics>
    {
        template <typename D> using type = consume_Windows_System_IProcessLauncherStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_IProcessMemoryReport
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) PrivateWorkingSetUsage() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) TotalWorkingSetUsage() const;
    };
    template <> struct consume<llm:OS::System::IProcessMemoryReport>
    {
        template <typename D> using type = consume_Windows_System_IProcessMemoryReport<D>;
    };
    template <typename D>
    struct consume_Windows_System_IProtocolForResultsOperation
    {
        LLM_IMPL_AUTO(void) ReportCompleted(llm:OS::Foundation::Collections::ValueSet const& data) const;
    };
    template <> struct consume<llm:OS::System::IProtocolForResultsOperation>
    {
        template <typename D> using type = consume_Windows_System_IProtocolForResultsOperation<D>;
    };
    template <typename D>
    struct consume_Windows_System_IRemoteLauncherOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Uri) FallbackUri() const;
        LLM_IMPL_AUTO(void) FallbackUri(llm:OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<hstring>) PreferredAppIds() const;
    };
    template <> struct consume<llm:OS::System::IRemoteLauncherOptions>
    {
        template <typename D> using type = consume_Windows_System_IRemoteLauncherOptions<D>;
    };
    template <typename D>
    struct consume_Windows_System_IRemoteLauncherStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::RemoteLaunchUriStatus>) LaunchUriAsync(llm:OS::System::RemoteSystems::RemoteSystemConnectionRequest const& remoteSystemConnectionRequest, llm:OS::Foundation::Uri const& uri) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::RemoteLaunchUriStatus>) LaunchUriAsync(llm:OS::System::RemoteSystems::RemoteSystemConnectionRequest const& remoteSystemConnectionRequest, llm:OS::Foundation::Uri const& uri, llm:OS::System::RemoteLauncherOptions const& options) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::RemoteLaunchUriStatus>) LaunchUriAsync(llm:OS::System::RemoteSystems::RemoteSystemConnectionRequest const& remoteSystemConnectionRequest, llm:OS::Foundation::Uri const& uri, llm:OS::System::RemoteLauncherOptions const& options, llm:OS::Foundation::Collections::ValueSet const& inputData) const;
    };
    template <> struct consume<llm:OS::System::IRemoteLauncherStatics>
    {
        template <typename D> using type = consume_Windows_System_IRemoteLauncherStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_IShutdownManagerStatics
    {
        LLM_IMPL_AUTO(void) BeginShutdown(llm:OS::System::ShutdownKind const& shutdownKind, llm:OS::Foundation::TimeSpan const& timeout) const;
        LLM_IMPL_AUTO(void) CancelShutdown() const;
    };
    template <> struct consume<llm:OS::System::IShutdownManagerStatics>
    {
        template <typename D> using type = consume_Windows_System_IShutdownManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_IShutdownManagerStatics2
    {
        LLM_IMPL_AUTO(bool) IsPowerStateSupported(llm:OS::System::PowerState const& powerState) const;
        LLM_IMPL_AUTO(void) EnterPowerState(llm:OS::System::PowerState const& powerState) const;
        LLM_IMPL_AUTO(void) EnterPowerState(llm:OS::System::PowerState const& powerState, llm:OS::Foundation::TimeSpan const& wakeUpAfter) const;
    };
    template <> struct consume<llm:OS::System::IShutdownManagerStatics2>
    {
        template <typename D> using type = consume_Windows_System_IShutdownManagerStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_System_ITimeZoneSettingsStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CurrentTimeZoneDisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<hstring>) SupportedTimeZoneDisplayNames() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) CanChangeTimeZone() const;
        LLM_IMPL_AUTO(void) ChangeTimeZoneByDisplayName(param::hstring const& timeZoneDisplayName) const;
    };
    template <> struct consume<llm:OS::System::ITimeZoneSettingsStatics>
    {
        template <typename D> using type = consume_Windows_System_ITimeZoneSettingsStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_ITimeZoneSettingsStatics2
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::AutoUpdateTimeZoneStatus>) AutoUpdateTimeZoneAsync(llm:OS::Foundation::TimeSpan const& timeout) const;
    };
    template <> struct consume<llm:OS::System::ITimeZoneSettingsStatics2>
    {
        template <typename D> using type = consume_Windows_System_ITimeZoneSettingsStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_System_IUser
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) NonRoamableId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::UserAuthenticationStatus) AuthenticationStatus() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::UserType) Type() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::IInspectable>) GetPropertyAsync(param::hstring const& value) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IPropertySet>) GetPropertiesAsync(param::async_vector_view<hstring> const& values) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Storage::Streams::IRandomAccessStreamReference>) GetPictureAsync(llm:OS::System::UserPictureSize const& desiredSize) const;
    };
    template <> struct consume<llm:OS::System::IUser>
    {
        template <typename D> using type = consume_Windows_System_IUser<D>;
    };
    template <typename D>
    struct consume_Windows_System_IUser2
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::UserAgeConsentResult>) CheckUserAgeConsentGroupAsync(llm:OS::System::UserAgeConsentGroup const& consentGroup) const;
    };
    template <> struct consume<llm:OS::System::IUser2>
    {
        template <typename D> using type = consume_Windows_System_IUser2<D>;
    };
    template <typename D>
    struct consume_Windows_System_IUserAuthenticationStatusChangeDeferral
    {
        LLM_IMPL_AUTO(void) Complete() const;
    };
    template <> struct consume<llm:OS::System::IUserAuthenticationStatusChangeDeferral>
    {
        template <typename D> using type = consume_Windows_System_IUserAuthenticationStatusChangeDeferral<D>;
    };
    template <typename D>
    struct consume_Windows_System_IUserAuthenticationStatusChangingEventArgs
    {
        LLM_IMPL_AUTO(llm:OS::System::UserAuthenticationStatusChangeDeferral) GetDeferral() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::User) User() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::UserAuthenticationStatus) NewStatus() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::UserAuthenticationStatus) CurrentStatus() const;
    };
    template <> struct consume<llm:OS::System::IUserAuthenticationStatusChangingEventArgs>
    {
        template <typename D> using type = consume_Windows_System_IUserAuthenticationStatusChangingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_System_IUserChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::User) User() const;
    };
    template <> struct consume<llm:OS::System::IUserChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_System_IUserChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_System_IUserChangedEventArgs2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::System::UserWatcherUpdateKind>) ChangedPropertyKinds() const;
    };
    template <> struct consume<llm:OS::System::IUserChangedEventArgs2>
    {
        template <typename D> using type = consume_Windows_System_IUserChangedEventArgs2<D>;
    };
    template <typename D>
    struct consume_Windows_System_IUserDeviceAssociationChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DeviceId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::User) NewUser() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::User) OldUser() const;
    };
    template <> struct consume<llm:OS::System::IUserDeviceAssociationChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_System_IUserDeviceAssociationChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_System_IUserDeviceAssociationStatics
    {
        LLM_IMPL_AUTO(llm:OS::System::User) FindUserFromDeviceId(param::hstring const& deviceId) const;
        LLM_IMPL_AUTO(llm::event_token) UserDeviceAssociationChanged(llm:OS::Foundation::EventHandler<llm:OS::System::UserDeviceAssociationChangedEventArgs> const& handler) const;
        using UserDeviceAssociationChanged_revoker = impl::event_revoker<llm:OS::System::IUserDeviceAssociationStatics, &impl::abi_t<llm:OS::System::IUserDeviceAssociationStatics>::remove_UserDeviceAssociationChanged>;
        [[nodiscard]] UserDeviceAssociationChanged_revoker UserDeviceAssociationChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::System::UserDeviceAssociationChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) UserDeviceAssociationChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::System::IUserDeviceAssociationStatics>
    {
        template <typename D> using type = consume_Windows_System_IUserDeviceAssociationStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_IUserPicker
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) AllowGuestAccounts() const;
        LLM_IMPL_AUTO(void) AllowGuestAccounts(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::User) SuggestedSelectedUser() const;
        LLM_IMPL_AUTO(void) SuggestedSelectedUser(llm:OS::System::User const& value) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::User>) PickSingleUserAsync() const;
    };
    template <> struct consume<llm:OS::System::IUserPicker>
    {
        template <typename D> using type = consume_Windows_System_IUserPicker<D>;
    };
    template <typename D>
    struct consume_Windows_System_IUserPickerStatics
    {
        LLM_IMPL_AUTO(bool) IsSupported() const;
    };
    template <> struct consume<llm:OS::System::IUserPickerStatics>
    {
        template <typename D> using type = consume_Windows_System_IUserPickerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_IUserStatics
    {
        LLM_IMPL_AUTO(llm:OS::System::UserWatcher) CreateWatcher() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::System::User>>) FindAllAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::System::User>>) FindAllAsync(llm:OS::System::UserType const& type) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::System::User>>) FindAllAsync(llm:OS::System::UserType const& type, llm:OS::System::UserAuthenticationStatus const& status) const;
        LLM_IMPL_AUTO(llm:OS::System::User) GetFromId(param::hstring const& nonRoamableId) const;
    };
    template <> struct consume<llm:OS::System::IUserStatics>
    {
        template <typename D> using type = consume_Windows_System_IUserStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_IUserStatics2
    {
        LLM_IMPL_AUTO(llm:OS::System::User) GetDefault() const;
    };
    template <> struct consume<llm:OS::System::IUserStatics2>
    {
        template <typename D> using type = consume_Windows_System_IUserStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_System_IUserWatcher
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::UserWatcherStatus) Status() const;
        LLM_IMPL_AUTO(void) Start() const;
        LLM_IMPL_AUTO(void) Stop() const;
        LLM_IMPL_AUTO(llm::event_token) Added(llm:OS::Foundation::TypedEventHandler<llm:OS::System::UserWatcher, llm:OS::System::UserChangedEventArgs> const& handler) const;
        using Added_revoker = impl::event_revoker<llm:OS::System::IUserWatcher, &impl::abi_t<llm:OS::System::IUserWatcher>::remove_Added>;
        [[nodiscard]] Added_revoker Added(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::UserWatcher, llm:OS::System::UserChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Added(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Removed(llm:OS::Foundation::TypedEventHandler<llm:OS::System::UserWatcher, llm:OS::System::UserChangedEventArgs> const& handler) const;
        using Removed_revoker = impl::event_revoker<llm:OS::System::IUserWatcher, &impl::abi_t<llm:OS::System::IUserWatcher>::remove_Removed>;
        [[nodiscard]] Removed_revoker Removed(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::UserWatcher, llm:OS::System::UserChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Removed(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Updated(llm:OS::Foundation::TypedEventHandler<llm:OS::System::UserWatcher, llm:OS::System::UserChangedEventArgs> const& handler) const;
        using Updated_revoker = impl::event_revoker<llm:OS::System::IUserWatcher, &impl::abi_t<llm:OS::System::IUserWatcher>::remove_Updated>;
        [[nodiscard]] Updated_revoker Updated(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::UserWatcher, llm:OS::System::UserChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Updated(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) AuthenticationStatusChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::System::UserWatcher, llm:OS::System::UserChangedEventArgs> const& handler) const;
        using AuthenticationStatusChanged_revoker = impl::event_revoker<llm:OS::System::IUserWatcher, &impl::abi_t<llm:OS::System::IUserWatcher>::remove_AuthenticationStatusChanged>;
        [[nodiscard]] AuthenticationStatusChanged_revoker AuthenticationStatusChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::UserWatcher, llm:OS::System::UserChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) AuthenticationStatusChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) AuthenticationStatusChanging(llm:OS::Foundation::TypedEventHandler<llm:OS::System::UserWatcher, llm:OS::System::UserAuthenticationStatusChangingEventArgs> const& handler) const;
        using AuthenticationStatusChanging_revoker = impl::event_revoker<llm:OS::System::IUserWatcher, &impl::abi_t<llm:OS::System::IUserWatcher>::remove_AuthenticationStatusChanging>;
        [[nodiscard]] AuthenticationStatusChanging_revoker AuthenticationStatusChanging(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::UserWatcher, llm:OS::System::UserAuthenticationStatusChangingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) AuthenticationStatusChanging(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) EnumerationCompleted(llm:OS::Foundation::TypedEventHandler<llm:OS::System::UserWatcher, llm:OS::Foundation::IInspectable> const& handler) const;
        using EnumerationCompleted_revoker = impl::event_revoker<llm:OS::System::IUserWatcher, &impl::abi_t<llm:OS::System::IUserWatcher>::remove_EnumerationCompleted>;
        [[nodiscard]] EnumerationCompleted_revoker EnumerationCompleted(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::UserWatcher, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) EnumerationCompleted(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Stopped(llm:OS::Foundation::TypedEventHandler<llm:OS::System::UserWatcher, llm:OS::Foundation::IInspectable> const& handler) const;
        using Stopped_revoker = impl::event_revoker<llm:OS::System::IUserWatcher, &impl::abi_t<llm:OS::System::IUserWatcher>::remove_Stopped>;
        [[nodiscard]] Stopped_revoker Stopped(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::UserWatcher, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Stopped(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::System::IUserWatcher>
    {
        template <typename D> using type = consume_Windows_System_IUserWatcher<D>;
    };
}
#endif
