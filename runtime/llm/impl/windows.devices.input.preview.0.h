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
#ifndef LLM_OS_Devices_Input_Preview_0_H
#define LLM_OS_Devices_Input_Preview_0_H
LLM_EXPORT namespace llm::OS::Devices::HumanInterfaceDevice
{
    struct HidBooleanControlDescription;
    struct HidInputReport;
    struct HidNumericControlDescription;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    struct Point;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm::OS::Devices::Input::Preview
{
    enum class GazeDeviceConfigurationStatePreview : int32_t
    {
        Unknown = 0,
        Ready = 1,
        Configuring = 2,
        ScreenSetupNeeded = 3,
        UserCalibrationNeeded = 4,
    };
    struct IGazeDevicePreview;
    struct IGazeDeviceWatcherAddedPreviewEventArgs;
    struct IGazeDeviceWatcherPreview;
    struct IGazeDeviceWatcherRemovedPreviewEventArgs;
    struct IGazeDeviceWatcherUpdatedPreviewEventArgs;
    struct IGazeEnteredPreviewEventArgs;
    struct IGazeExitedPreviewEventArgs;
    struct IGazeInputSourcePreview;
    struct IGazeInputSourcePreviewStatics;
    struct IGazeMovedPreviewEventArgs;
    struct IGazePointPreview;
    struct GazeDevicePreview;
    struct GazeDeviceWatcherAddedPreviewEventArgs;
    struct GazeDeviceWatcherPreview;
    struct GazeDeviceWatcherRemovedPreviewEventArgs;
    struct GazeDeviceWatcherUpdatedPreviewEventArgs;
    struct GazeEnteredPreviewEventArgs;
    struct GazeExitedPreviewEventArgs;
    struct GazeInputSourcePreview;
    struct GazeMovedPreviewEventArgs;
    struct GazePointPreview;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::Input::Preview::IGazeDevicePreview>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherAddedPreviewEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherPreview>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherRemovedPreviewEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherUpdatedPreviewEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::IGazeEnteredPreviewEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::IGazeExitedPreviewEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::IGazeInputSourcePreview>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::IGazeInputSourcePreviewStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::IGazeMovedPreviewEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::IGazePointPreview>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::GazeDevicePreview>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::GazeDeviceWatcherAddedPreviewEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::GazeDeviceWatcherPreview>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::GazeDeviceWatcherRemovedPreviewEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::GazeDeviceWatcherUpdatedPreviewEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::GazeEnteredPreviewEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::GazeExitedPreviewEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::GazeInputSourcePreview>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::GazeMovedPreviewEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::GazePointPreview>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Input::Preview::GazeDeviceConfigurationStatePreview>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::GazeDevicePreview> = L"Windows.Devices.Input.Preview.GazeDevicePreview";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::GazeDeviceWatcherAddedPreviewEventArgs> = L"Windows.Devices.Input.Preview.GazeDeviceWatcherAddedPreviewEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::GazeDeviceWatcherPreview> = L"Windows.Devices.Input.Preview.GazeDeviceWatcherPreview";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::GazeDeviceWatcherRemovedPreviewEventArgs> = L"Windows.Devices.Input.Preview.GazeDeviceWatcherRemovedPreviewEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::GazeDeviceWatcherUpdatedPreviewEventArgs> = L"Windows.Devices.Input.Preview.GazeDeviceWatcherUpdatedPreviewEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::GazeEnteredPreviewEventArgs> = L"Windows.Devices.Input.Preview.GazeEnteredPreviewEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::GazeExitedPreviewEventArgs> = L"Windows.Devices.Input.Preview.GazeExitedPreviewEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::GazeInputSourcePreview> = L"Windows.Devices.Input.Preview.GazeInputSourcePreview";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::GazeMovedPreviewEventArgs> = L"Windows.Devices.Input.Preview.GazeMovedPreviewEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::GazePointPreview> = L"Windows.Devices.Input.Preview.GazePointPreview";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::GazeDeviceConfigurationStatePreview> = L"Windows.Devices.Input.Preview.GazeDeviceConfigurationStatePreview";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::IGazeDevicePreview> = L"Windows.Devices.Input.Preview.IGazeDevicePreview";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherAddedPreviewEventArgs> = L"Windows.Devices.Input.Preview.IGazeDeviceWatcherAddedPreviewEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherPreview> = L"Windows.Devices.Input.Preview.IGazeDeviceWatcherPreview";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherRemovedPreviewEventArgs> = L"Windows.Devices.Input.Preview.IGazeDeviceWatcherRemovedPreviewEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherUpdatedPreviewEventArgs> = L"Windows.Devices.Input.Preview.IGazeDeviceWatcherUpdatedPreviewEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::IGazeEnteredPreviewEventArgs> = L"Windows.Devices.Input.Preview.IGazeEnteredPreviewEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::IGazeExitedPreviewEventArgs> = L"Windows.Devices.Input.Preview.IGazeExitedPreviewEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::IGazeInputSourcePreview> = L"Windows.Devices.Input.Preview.IGazeInputSourcePreview";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::IGazeInputSourcePreviewStatics> = L"Windows.Devices.Input.Preview.IGazeInputSourcePreviewStatics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::IGazeMovedPreviewEventArgs> = L"Windows.Devices.Input.Preview.IGazeMovedPreviewEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Input::Preview::IGazePointPreview> = L"Windows.Devices.Input.Preview.IGazePointPreview";
    template <> inline constexpr guid guid_v<llm::OS::Devices::Input::Preview::IGazeDevicePreview>{ 0xE79E7EE9,0xB389,0x11E7,{ 0xB2,0x01,0xC8,0xD3,0xFF,0xB7,0x57,0x21 } }; // E79E7EE9-B389-11E7-B201-C8D3FFB75721
    template <> inline constexpr guid guid_v<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherAddedPreviewEventArgs>{ 0xE79E7EED,0xB389,0x11E7,{ 0xB2,0x01,0xC8,0xD3,0xFF,0xB7,0x57,0x21 } }; // E79E7EED-B389-11E7-B201-C8D3FFB75721
    template <> inline constexpr guid guid_v<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherPreview>{ 0xE79E7EE7,0xB389,0x11E7,{ 0xB2,0x01,0xC8,0xD3,0xFF,0xB7,0x57,0x21 } }; // E79E7EE7-B389-11E7-B201-C8D3FFB75721
    template <> inline constexpr guid guid_v<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherRemovedPreviewEventArgs>{ 0xF2631F08,0x0E3F,0x431F,{ 0xA6,0x06,0x50,0xB3,0x5A,0xF9,0x4A,0x1C } }; // F2631F08-0E3F-431F-A606-50B35AF94A1C
    template <> inline constexpr guid guid_v<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherUpdatedPreviewEventArgs>{ 0x7FE830EF,0x7F08,0x4737,{ 0x88,0xE1,0x4A,0x83,0xAE,0x4E,0x48,0x85 } }; // 7FE830EF-7F08-4737-88E1-4A83AE4E4885
    template <> inline constexpr guid guid_v<llm::OS::Devices::Input::Preview::IGazeEnteredPreviewEventArgs>{ 0x2567BF43,0x1225,0x489F,{ 0x9D,0xD1,0xDA,0xA7,0xC5,0x0F,0xBF,0x4B } }; // 2567BF43-1225-489F-9DD1-DAA7C50FBF4B
    template <> inline constexpr guid guid_v<llm::OS::Devices::Input::Preview::IGazeExitedPreviewEventArgs>{ 0x5D0AF07E,0x7D83,0x40EF,{ 0x9F,0x0A,0xFB,0xC1,0xBB,0xDC,0xC5,0xAC } }; // 5D0AF07E-7D83-40EF-9F0A-FBC1BBDCC5AC
    template <> inline constexpr guid guid_v<llm::OS::Devices::Input::Preview::IGazeInputSourcePreview>{ 0xE79E7EE8,0xB389,0x11E7,{ 0xB2,0x01,0xC8,0xD3,0xFF,0xB7,0x57,0x21 } }; // E79E7EE8-B389-11E7-B201-C8D3FFB75721
    template <> inline constexpr guid guid_v<llm::OS::Devices::Input::Preview::IGazeInputSourcePreviewStatics>{ 0xE79E7EE6,0xB389,0x11E7,{ 0xB2,0x01,0xC8,0xD3,0xFF,0xB7,0x57,0x21 } }; // E79E7EE6-B389-11E7-B201-C8D3FFB75721
    template <> inline constexpr guid guid_v<llm::OS::Devices::Input::Preview::IGazeMovedPreviewEventArgs>{ 0xE79E7EEB,0xB389,0x11E7,{ 0xB2,0x01,0xC8,0xD3,0xFF,0xB7,0x57,0x21 } }; // E79E7EEB-B389-11E7-B201-C8D3FFB75721
    template <> inline constexpr guid guid_v<llm::OS::Devices::Input::Preview::IGazePointPreview>{ 0xE79E7EEA,0xB389,0x11E7,{ 0xB2,0x01,0xC8,0xD3,0xFF,0xB7,0x57,0x21 } }; // E79E7EEA-B389-11E7-B201-C8D3FFB75721
    template <> struct default_interface<llm::OS::Devices::Input::Preview::GazeDevicePreview>{ using type = llm::OS::Devices::Input::Preview::IGazeDevicePreview; };
    template <> struct default_interface<llm::OS::Devices::Input::Preview::GazeDeviceWatcherAddedPreviewEventArgs>{ using type = llm::OS::Devices::Input::Preview::IGazeDeviceWatcherAddedPreviewEventArgs; };
    template <> struct default_interface<llm::OS::Devices::Input::Preview::GazeDeviceWatcherPreview>{ using type = llm::OS::Devices::Input::Preview::IGazeDeviceWatcherPreview; };
    template <> struct default_interface<llm::OS::Devices::Input::Preview::GazeDeviceWatcherRemovedPreviewEventArgs>{ using type = llm::OS::Devices::Input::Preview::IGazeDeviceWatcherRemovedPreviewEventArgs; };
    template <> struct default_interface<llm::OS::Devices::Input::Preview::GazeDeviceWatcherUpdatedPreviewEventArgs>{ using type = llm::OS::Devices::Input::Preview::IGazeDeviceWatcherUpdatedPreviewEventArgs; };
    template <> struct default_interface<llm::OS::Devices::Input::Preview::GazeEnteredPreviewEventArgs>{ using type = llm::OS::Devices::Input::Preview::IGazeEnteredPreviewEventArgs; };
    template <> struct default_interface<llm::OS::Devices::Input::Preview::GazeExitedPreviewEventArgs>{ using type = llm::OS::Devices::Input::Preview::IGazeExitedPreviewEventArgs; };
    template <> struct default_interface<llm::OS::Devices::Input::Preview::GazeInputSourcePreview>{ using type = llm::OS::Devices::Input::Preview::IGazeInputSourcePreview; };
    template <> struct default_interface<llm::OS::Devices::Input::Preview::GazeMovedPreviewEventArgs>{ using type = llm::OS::Devices::Input::Preview::IGazeMovedPreviewEventArgs; };
    template <> struct default_interface<llm::OS::Devices::Input::Preview::GazePointPreview>{ using type = llm::OS::Devices::Input::Preview::IGazePointPreview; };
    template <> struct abi<llm::OS::Devices::Input::Preview::IGazeDevicePreview>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_CanTrackEyes(bool*) noexcept = 0;
            virtual int32_t __stdcall get_CanTrackHead(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ConfigurationState(int32_t*) noexcept = 0;
            virtual int32_t __stdcall RequestCalibrationAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetNumericControlDescriptions(uint16_t, uint16_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetBooleanControlDescriptions(uint16_t, uint16_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherAddedPreviewEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Device(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherPreview>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_Added(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Added(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Removed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Removed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Updated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Updated(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_EnumerationCompleted(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_EnumerationCompleted(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall Start() noexcept = 0;
            virtual int32_t __stdcall Stop() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherRemovedPreviewEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Device(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherUpdatedPreviewEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Device(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Input::Preview::IGazeEnteredPreviewEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
            virtual int32_t __stdcall get_CurrentPoint(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Input::Preview::IGazeExitedPreviewEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
            virtual int32_t __stdcall get_CurrentPoint(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Input::Preview::IGazeInputSourcePreview>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_GazeMoved(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_GazeMoved(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_GazeEntered(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_GazeEntered(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_GazeExited(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_GazeExited(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Input::Preview::IGazeInputSourcePreviewStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForCurrentView(void**) noexcept = 0;
            virtual int32_t __stdcall CreateWatcher(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Input::Preview::IGazeMovedPreviewEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
            virtual int32_t __stdcall get_CurrentPoint(void**) noexcept = 0;
            virtual int32_t __stdcall GetIntermediatePoints(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Input::Preview::IGazePointPreview>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SourceDevice(void**) noexcept = 0;
            virtual int32_t __stdcall get_EyeGazePosition(void**) noexcept = 0;
            virtual int32_t __stdcall get_HeadGazePosition(void**) noexcept = 0;
            virtual int32_t __stdcall get_Timestamp(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_HidInputReport(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Input_Preview_IGazeDevicePreview
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) CanTrackEyes() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) CanTrackHead() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Input::Preview::GazeDeviceConfigurationStatePreview) ConfigurationState() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) RequestCalibrationAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::HumanInterfaceDevice::HidNumericControlDescription>) GetNumericControlDescriptions(uint16_t usagePage, uint16_t usageId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::HumanInterfaceDevice::HidBooleanControlDescription>) GetBooleanControlDescriptions(uint16_t usagePage, uint16_t usageId) const;
    };
    template <> struct consume<llm::OS::Devices::Input::Preview::IGazeDevicePreview>
    {
        template <typename D> using type = consume_Windows_Devices_Input_Preview_IGazeDevicePreview<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Input_Preview_IGazeDeviceWatcherAddedPreviewEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Input::Preview::GazeDevicePreview) Device() const;
    };
    template <> struct consume<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherAddedPreviewEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_Input_Preview_IGazeDeviceWatcherAddedPreviewEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Input_Preview_IGazeDeviceWatcherPreview
    {
        LLM_IMPL_AUTO(llm::event_token) Added(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::Preview::GazeDeviceWatcherPreview, llm::OS::Devices::Input::Preview::GazeDeviceWatcherAddedPreviewEventArgs> const& handler) const;
        using Added_revoker = impl::event_revoker<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherPreview, &impl::abi_t<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherPreview>::remove_Added>;
        [[nodiscard]] Added_revoker Added(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::Preview::GazeDeviceWatcherPreview, llm::OS::Devices::Input::Preview::GazeDeviceWatcherAddedPreviewEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Added(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Removed(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::Preview::GazeDeviceWatcherPreview, llm::OS::Devices::Input::Preview::GazeDeviceWatcherRemovedPreviewEventArgs> const& handler) const;
        using Removed_revoker = impl::event_revoker<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherPreview, &impl::abi_t<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherPreview>::remove_Removed>;
        [[nodiscard]] Removed_revoker Removed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::Preview::GazeDeviceWatcherPreview, llm::OS::Devices::Input::Preview::GazeDeviceWatcherRemovedPreviewEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Removed(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Updated(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::Preview::GazeDeviceWatcherPreview, llm::OS::Devices::Input::Preview::GazeDeviceWatcherUpdatedPreviewEventArgs> const& handler) const;
        using Updated_revoker = impl::event_revoker<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherPreview, &impl::abi_t<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherPreview>::remove_Updated>;
        [[nodiscard]] Updated_revoker Updated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::Preview::GazeDeviceWatcherPreview, llm::OS::Devices::Input::Preview::GazeDeviceWatcherUpdatedPreviewEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Updated(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) EnumerationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::Preview::GazeDeviceWatcherPreview, llm::OS::Foundation::IInspectable> const& handler) const;
        using EnumerationCompleted_revoker = impl::event_revoker<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherPreview, &impl::abi_t<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherPreview>::remove_EnumerationCompleted>;
        [[nodiscard]] EnumerationCompleted_revoker EnumerationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::Preview::GazeDeviceWatcherPreview, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) EnumerationCompleted(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(void) Start() const;
        LLM_IMPL_AUTO(void) Stop() const;
    };
    template <> struct consume<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherPreview>
    {
        template <typename D> using type = consume_Windows_Devices_Input_Preview_IGazeDeviceWatcherPreview<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Input_Preview_IGazeDeviceWatcherRemovedPreviewEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Input::Preview::GazeDevicePreview) Device() const;
    };
    template <> struct consume<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherRemovedPreviewEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_Input_Preview_IGazeDeviceWatcherRemovedPreviewEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Input_Preview_IGazeDeviceWatcherUpdatedPreviewEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Input::Preview::GazeDevicePreview) Device() const;
    };
    template <> struct consume<llm::OS::Devices::Input::Preview::IGazeDeviceWatcherUpdatedPreviewEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_Input_Preview_IGazeDeviceWatcherUpdatedPreviewEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Input_Preview_IGazeEnteredPreviewEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Handled() const;
        LLM_IMPL_AUTO(void) Handled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Input::Preview::GazePointPreview) CurrentPoint() const;
    };
    template <> struct consume<llm::OS::Devices::Input::Preview::IGazeEnteredPreviewEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_Input_Preview_IGazeEnteredPreviewEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Input_Preview_IGazeExitedPreviewEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Handled() const;
        LLM_IMPL_AUTO(void) Handled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Input::Preview::GazePointPreview) CurrentPoint() const;
    };
    template <> struct consume<llm::OS::Devices::Input::Preview::IGazeExitedPreviewEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_Input_Preview_IGazeExitedPreviewEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Input_Preview_IGazeInputSourcePreview
    {
        LLM_IMPL_AUTO(llm::event_token) GazeMoved(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::Preview::GazeInputSourcePreview, llm::OS::Devices::Input::Preview::GazeMovedPreviewEventArgs> const& handler) const;
        using GazeMoved_revoker = impl::event_revoker<llm::OS::Devices::Input::Preview::IGazeInputSourcePreview, &impl::abi_t<llm::OS::Devices::Input::Preview::IGazeInputSourcePreview>::remove_GazeMoved>;
        [[nodiscard]] GazeMoved_revoker GazeMoved(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::Preview::GazeInputSourcePreview, llm::OS::Devices::Input::Preview::GazeMovedPreviewEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) GazeMoved(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) GazeEntered(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::Preview::GazeInputSourcePreview, llm::OS::Devices::Input::Preview::GazeEnteredPreviewEventArgs> const& handler) const;
        using GazeEntered_revoker = impl::event_revoker<llm::OS::Devices::Input::Preview::IGazeInputSourcePreview, &impl::abi_t<llm::OS::Devices::Input::Preview::IGazeInputSourcePreview>::remove_GazeEntered>;
        [[nodiscard]] GazeEntered_revoker GazeEntered(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::Preview::GazeInputSourcePreview, llm::OS::Devices::Input::Preview::GazeEnteredPreviewEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) GazeEntered(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) GazeExited(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::Preview::GazeInputSourcePreview, llm::OS::Devices::Input::Preview::GazeExitedPreviewEventArgs> const& handler) const;
        using GazeExited_revoker = impl::event_revoker<llm::OS::Devices::Input::Preview::IGazeInputSourcePreview, &impl::abi_t<llm::OS::Devices::Input::Preview::IGazeInputSourcePreview>::remove_GazeExited>;
        [[nodiscard]] GazeExited_revoker GazeExited(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::Preview::GazeInputSourcePreview, llm::OS::Devices::Input::Preview::GazeExitedPreviewEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) GazeExited(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::Devices::Input::Preview::IGazeInputSourcePreview>
    {
        template <typename D> using type = consume_Windows_Devices_Input_Preview_IGazeInputSourcePreview<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Input_Preview_IGazeInputSourcePreviewStatics
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Input::Preview::GazeInputSourcePreview) GetForCurrentView() const;
        LLM_IMPL_AUTO(llm::OS::Devices::Input::Preview::GazeDeviceWatcherPreview) CreateWatcher() const;
    };
    template <> struct consume<llm::OS::Devices::Input::Preview::IGazeInputSourcePreviewStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Input_Preview_IGazeInputSourcePreviewStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Input_Preview_IGazeMovedPreviewEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Handled() const;
        LLM_IMPL_AUTO(void) Handled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Input::Preview::GazePointPreview) CurrentPoint() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Input::Preview::GazePointPreview>) GetIntermediatePoints() const;
    };
    template <> struct consume<llm::OS::Devices::Input::Preview::IGazeMovedPreviewEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_Input_Preview_IGazeMovedPreviewEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Input_Preview_IGazePointPreview
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Input::Preview::GazeDevicePreview) SourceDevice() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::Point>) EyeGazePosition() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::Point>) HeadGazePosition() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) Timestamp() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::HumanInterfaceDevice::HidInputReport) HidInputReport() const;
    };
    template <> struct consume<llm::OS::Devices::Input::Preview::IGazePointPreview>
    {
        template <typename D> using type = consume_Windows_Devices_Input_Preview_IGazePointPreview<D>;
    };
}
#endif
