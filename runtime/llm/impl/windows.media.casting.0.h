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
#ifndef LLM_OS_Media_Casting_0_H
#define LLM_OS_Media_Casting_0_H
LLM_EXPORT namespace llm:OS::Devices::Enumeration
{
    struct DeviceInformation;
    struct DevicePickerAppearance;
}
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    struct Rect;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
    struct Uri;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IRandomAccessStreamWithContentType;
}
LLM_EXPORT namespace llm:OS::UI::Popups
{
    enum class Placement : int32_t;
}
LLM_EXPORT namespace llm:OS::Media::Casting
{
    enum class CastingConnectionErrorStatus : int32_t
    {
        Succeeded = 0,
        DeviceDidNotRespond = 1,
        DeviceError = 2,
        DeviceLocked = 3,
        ProtectedPlaybackFailed = 4,
        InvalidCastingSource = 5,
        Unknown = 6,
    };
    enum class CastingConnectionState : int32_t
    {
        Disconnected = 0,
        Connected = 1,
        Rendering = 2,
        Disconnecting = 3,
        Connecting = 4,
    };
    enum class CastingPlaybackTypes : uint32_t
    {
        None = 0,
        Audio = 0x1,
        Video = 0x2,
        Picture = 0x4,
    };
    struct ICastingConnection;
    struct ICastingConnectionErrorOccurredEventArgs;
    struct ICastingDevice;
    struct ICastingDevicePicker;
    struct ICastingDevicePickerFilter;
    struct ICastingDeviceSelectedEventArgs;
    struct ICastingDeviceStatics;
    struct ICastingSource;
    struct CastingConnection;
    struct CastingConnectionErrorOccurredEventArgs;
    struct CastingDevice;
    struct CastingDevicePicker;
    struct CastingDevicePickerFilter;
    struct CastingDeviceSelectedEventArgs;
    struct CastingSource;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::Casting::ICastingConnection>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Casting::ICastingConnectionErrorOccurredEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Casting::ICastingDevice>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Casting::ICastingDevicePicker>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Casting::ICastingDevicePickerFilter>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Casting::ICastingDeviceSelectedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Casting::ICastingDeviceStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Casting::ICastingSource>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Casting::CastingConnection>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Casting::CastingConnectionErrorOccurredEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Casting::CastingDevice>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Casting::CastingDevicePicker>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Casting::CastingDevicePickerFilter>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Casting::CastingDeviceSelectedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Casting::CastingSource>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Casting::CastingConnectionErrorStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Casting::CastingConnectionState>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Casting::CastingPlaybackTypes>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::CastingConnection> = L"Windows.Media.Casting.CastingConnection";
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::CastingConnectionErrorOccurredEventArgs> = L"Windows.Media.Casting.CastingConnectionErrorOccurredEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::CastingDevice> = L"Windows.Media.Casting.CastingDevice";
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::CastingDevicePicker> = L"Windows.Media.Casting.CastingDevicePicker";
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::CastingDevicePickerFilter> = L"Windows.Media.Casting.CastingDevicePickerFilter";
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::CastingDeviceSelectedEventArgs> = L"Windows.Media.Casting.CastingDeviceSelectedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::CastingSource> = L"Windows.Media.Casting.CastingSource";
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::CastingConnectionErrorStatus> = L"Windows.Media.Casting.CastingConnectionErrorStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::CastingConnectionState> = L"Windows.Media.Casting.CastingConnectionState";
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::CastingPlaybackTypes> = L"Windows.Media.Casting.CastingPlaybackTypes";
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::ICastingConnection> = L"Windows.Media.Casting.ICastingConnection";
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::ICastingConnectionErrorOccurredEventArgs> = L"Windows.Media.Casting.ICastingConnectionErrorOccurredEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::ICastingDevice> = L"Windows.Media.Casting.ICastingDevice";
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::ICastingDevicePicker> = L"Windows.Media.Casting.ICastingDevicePicker";
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::ICastingDevicePickerFilter> = L"Windows.Media.Casting.ICastingDevicePickerFilter";
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::ICastingDeviceSelectedEventArgs> = L"Windows.Media.Casting.ICastingDeviceSelectedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::ICastingDeviceStatics> = L"Windows.Media.Casting.ICastingDeviceStatics";
    template <> inline constexpr auto& name_v<llm:OS::Media::Casting::ICastingSource> = L"Windows.Media.Casting.ICastingSource";
    template <> inline constexpr guid guid_v<llm:OS::Media::Casting::ICastingConnection>{ 0xCD951653,0xC2F1,0x4498,{ 0x8B,0x78,0x5F,0xB4,0xCD,0x36,0x40,0xDD } }; // CD951653-C2F1-4498-8B78-5FB4CD3640DD
    template <> inline constexpr guid guid_v<llm:OS::Media::Casting::ICastingConnectionErrorOccurredEventArgs>{ 0xA7FB3C69,0x8719,0x4F00,{ 0x81,0xFB,0x96,0x18,0x63,0xC7,0x9A,0x32 } }; // A7FB3C69-8719-4F00-81FB-961863C79A32
    template <> inline constexpr guid guid_v<llm:OS::Media::Casting::ICastingDevice>{ 0xDE721C83,0x4A43,0x4AD1,{ 0xA6,0xD2,0x24,0x92,0xA7,0x96,0xC3,0xF2 } }; // DE721C83-4A43-4AD1-A6D2-2492A796C3F2
    template <> inline constexpr guid guid_v<llm:OS::Media::Casting::ICastingDevicePicker>{ 0xDCD39924,0x0591,0x49BE,{ 0xAA,0xCB,0x4B,0x82,0xEE,0x75,0x6A,0x95 } }; // DCD39924-0591-49BE-AACB-4B82EE756A95
    template <> inline constexpr guid guid_v<llm:OS::Media::Casting::ICastingDevicePickerFilter>{ 0xBE8C619C,0xB563,0x4354,{ 0xAE,0x33,0x9F,0xDA,0xAD,0x8C,0x62,0x91 } }; // BE8C619C-B563-4354-AE33-9FDAAD8C6291
    template <> inline constexpr guid guid_v<llm:OS::Media::Casting::ICastingDeviceSelectedEventArgs>{ 0xDC439E86,0xDD57,0x4D0D,{ 0x94,0x00,0xAF,0x45,0xE4,0xFB,0x36,0x63 } }; // DC439E86-DD57-4D0D-9400-AF45E4FB3663
    template <> inline constexpr guid guid_v<llm:OS::Media::Casting::ICastingDeviceStatics>{ 0xE7D958D7,0x4D13,0x4237,{ 0xA3,0x65,0x4C,0x4F,0x6A,0x4C,0xFD,0x2F } }; // E7D958D7-4D13-4237-A365-4C4F6A4CFD2F
    template <> inline constexpr guid guid_v<llm:OS::Media::Casting::ICastingSource>{ 0xF429EA72,0x3467,0x47E6,{ 0xA0,0x27,0x52,0x29,0x23,0xE9,0xD7,0x27 } }; // F429EA72-3467-47E6-A027-522923E9D727
    template <> struct default_interface<llm:OS::Media::Casting::CastingConnection>{ using type = llm:OS::Media::Casting::ICastingConnection; };
    template <> struct default_interface<llm:OS::Media::Casting::CastingConnectionErrorOccurredEventArgs>{ using type = llm:OS::Media::Casting::ICastingConnectionErrorOccurredEventArgs; };
    template <> struct default_interface<llm:OS::Media::Casting::CastingDevice>{ using type = llm:OS::Media::Casting::ICastingDevice; };
    template <> struct default_interface<llm:OS::Media::Casting::CastingDevicePicker>{ using type = llm:OS::Media::Casting::ICastingDevicePicker; };
    template <> struct default_interface<llm:OS::Media::Casting::CastingDevicePickerFilter>{ using type = llm:OS::Media::Casting::ICastingDevicePickerFilter; };
    template <> struct default_interface<llm:OS::Media::Casting::CastingDeviceSelectedEventArgs>{ using type = llm:OS::Media::Casting::ICastingDeviceSelectedEventArgs; };
    template <> struct default_interface<llm:OS::Media::Casting::CastingSource>{ using type = llm:OS::Media::Casting::ICastingSource; };
    template <> struct abi<llm:OS::Media::Casting::ICastingConnection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_State(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Device(void**) noexcept = 0;
            virtual int32_t __stdcall get_Source(void**) noexcept = 0;
            virtual int32_t __stdcall put_Source(void*) noexcept = 0;
            virtual int32_t __stdcall add_StateChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_StateChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ErrorOccurred(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ErrorOccurred(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall RequestStartCastingAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DisconnectAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Casting::ICastingConnectionErrorOccurredEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ErrorStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Message(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Casting::ICastingDevice>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_FriendlyName(void**) noexcept = 0;
            virtual int32_t __stdcall get_Icon(void**) noexcept = 0;
            virtual int32_t __stdcall GetSupportedCastingPlaybackTypesAsync(void**) noexcept = 0;
            virtual int32_t __stdcall CreateCastingConnection(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Casting::ICastingDevicePicker>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Filter(void**) noexcept = 0;
            virtual int32_t __stdcall get_Appearance(void**) noexcept = 0;
            virtual int32_t __stdcall add_CastingDeviceSelected(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_CastingDeviceSelected(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_CastingDevicePickerDismissed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_CastingDevicePickerDismissed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall Show(llm:OS::Foundation::Rect) noexcept = 0;
            virtual int32_t __stdcall ShowWithPlacement(llm:OS::Foundation::Rect, int32_t) noexcept = 0;
            virtual int32_t __stdcall Hide() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Casting::ICastingDevicePickerFilter>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SupportsAudio(bool*) noexcept = 0;
            virtual int32_t __stdcall put_SupportsAudio(bool) noexcept = 0;
            virtual int32_t __stdcall get_SupportsVideo(bool*) noexcept = 0;
            virtual int32_t __stdcall put_SupportsVideo(bool) noexcept = 0;
            virtual int32_t __stdcall get_SupportsPictures(bool*) noexcept = 0;
            virtual int32_t __stdcall put_SupportsPictures(bool) noexcept = 0;
            virtual int32_t __stdcall get_SupportedCastingSources(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Casting::ICastingDeviceSelectedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SelectedCastingDevice(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Casting::ICastingDeviceStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeviceSelector(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetDeviceSelectorFromCastingSourceAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall FromIdAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DeviceInfoSupportsCastingAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Casting::ICastingSource>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PreferredSourceUri(void**) noexcept = 0;
            virtual int32_t __stdcall put_PreferredSourceUri(void*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_Casting_ICastingConnection
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Casting::CastingConnectionState) State() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Casting::CastingDevice) Device() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Casting::CastingSource) Source() const;
        LLM_IMPL_AUTO(void) Source(llm:OS::Media::Casting::CastingSource const& value) const;
        LLM_IMPL_AUTO(llm::event_token) StateChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Casting::CastingConnection, llm:OS::Foundation::IInspectable> const& handler) const;
        using StateChanged_revoker = impl::event_revoker<llm:OS::Media::Casting::ICastingConnection, &impl::abi_t<llm:OS::Media::Casting::ICastingConnection>::remove_StateChanged>;
        [[nodiscard]] StateChanged_revoker StateChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Casting::CastingConnection, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) StateChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ErrorOccurred(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Casting::CastingConnection, llm:OS::Media::Casting::CastingConnectionErrorOccurredEventArgs> const& handler) const;
        using ErrorOccurred_revoker = impl::event_revoker<llm:OS::Media::Casting::ICastingConnection, &impl::abi_t<llm:OS::Media::Casting::ICastingConnection>::remove_ErrorOccurred>;
        [[nodiscard]] ErrorOccurred_revoker ErrorOccurred(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Casting::CastingConnection, llm:OS::Media::Casting::CastingConnectionErrorOccurredEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) ErrorOccurred(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Casting::CastingConnectionErrorStatus>) RequestStartCastingAsync(llm:OS::Media::Casting::CastingSource const& value) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Casting::CastingConnectionErrorStatus>) DisconnectAsync() const;
    };
    template <> struct consume<llm:OS::Media::Casting::ICastingConnection>
    {
        template <typename D> using type = consume_Windows_Media_Casting_ICastingConnection<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Casting_ICastingConnectionErrorOccurredEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Casting::CastingConnectionErrorStatus) ErrorStatus() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Message() const;
    };
    template <> struct consume<llm:OS::Media::Casting::ICastingConnectionErrorOccurredEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_Casting_ICastingConnectionErrorOccurredEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Casting_ICastingDevice
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) FriendlyName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IRandomAccessStreamWithContentType) Icon() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Casting::CastingPlaybackTypes>) GetSupportedCastingPlaybackTypesAsync() const;
        LLM_IMPL_AUTO(llm:OS::Media::Casting::CastingConnection) CreateCastingConnection() const;
    };
    template <> struct consume<llm:OS::Media::Casting::ICastingDevice>
    {
        template <typename D> using type = consume_Windows_Media_Casting_ICastingDevice<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Casting_ICastingDevicePicker
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Casting::CastingDevicePickerFilter) Filter() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Devices::Enumeration::DevicePickerAppearance) Appearance() const;
        LLM_IMPL_AUTO(llm::event_token) CastingDeviceSelected(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Casting::CastingDevicePicker, llm:OS::Media::Casting::CastingDeviceSelectedEventArgs> const& handler) const;
        using CastingDeviceSelected_revoker = impl::event_revoker<llm:OS::Media::Casting::ICastingDevicePicker, &impl::abi_t<llm:OS::Media::Casting::ICastingDevicePicker>::remove_CastingDeviceSelected>;
        [[nodiscard]] CastingDeviceSelected_revoker CastingDeviceSelected(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Casting::CastingDevicePicker, llm:OS::Media::Casting::CastingDeviceSelectedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) CastingDeviceSelected(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) CastingDevicePickerDismissed(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Casting::CastingDevicePicker, llm:OS::Foundation::IInspectable> const& handler) const;
        using CastingDevicePickerDismissed_revoker = impl::event_revoker<llm:OS::Media::Casting::ICastingDevicePicker, &impl::abi_t<llm:OS::Media::Casting::ICastingDevicePicker>::remove_CastingDevicePickerDismissed>;
        [[nodiscard]] CastingDevicePickerDismissed_revoker CastingDevicePickerDismissed(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Casting::CastingDevicePicker, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) CastingDevicePickerDismissed(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(void) Show(llm:OS::Foundation::Rect const& selection) const;
        LLM_IMPL_AUTO(void) Show(llm:OS::Foundation::Rect const& selection, llm:OS::UI::Popups::Placement const& preferredPlacement) const;
        LLM_IMPL_AUTO(void) Hide() const;
    };
    template <> struct consume<llm:OS::Media::Casting::ICastingDevicePicker>
    {
        template <typename D> using type = consume_Windows_Media_Casting_ICastingDevicePicker<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Casting_ICastingDevicePickerFilter
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) SupportsAudio() const;
        LLM_IMPL_AUTO(void) SupportsAudio(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) SupportsVideo() const;
        LLM_IMPL_AUTO(void) SupportsVideo(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) SupportsPictures() const;
        LLM_IMPL_AUTO(void) SupportsPictures(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::Media::Casting::CastingSource>) SupportedCastingSources() const;
    };
    template <> struct consume<llm:OS::Media::Casting::ICastingDevicePickerFilter>
    {
        template <typename D> using type = consume_Windows_Media_Casting_ICastingDevicePickerFilter<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Casting_ICastingDeviceSelectedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Casting::CastingDevice) SelectedCastingDevice() const;
    };
    template <> struct consume<llm:OS::Media::Casting::ICastingDeviceSelectedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_Casting_ICastingDeviceSelectedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Casting_ICastingDeviceStatics
    {
        LLM_IMPL_AUTO(hstring) GetDeviceSelector(llm:OS::Media::Casting::CastingPlaybackTypes const& type) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<hstring>) GetDeviceSelectorFromCastingSourceAsync(llm:OS::Media::Casting::CastingSource const& castingSource) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Casting::CastingDevice>) FromIdAsync(param::hstring const& value) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) DeviceInfoSupportsCastingAsync(llm:OS::Devices::Enumeration::DeviceInformation const& device) const;
    };
    template <> struct consume<llm:OS::Media::Casting::ICastingDeviceStatics>
    {
        template <typename D> using type = consume_Windows_Media_Casting_ICastingDeviceStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Casting_ICastingSource
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Uri) PreferredSourceUri() const;
        LLM_IMPL_AUTO(void) PreferredSourceUri(llm:OS::Foundation::Uri const& value) const;
    };
    template <> struct consume<llm:OS::Media::Casting::ICastingSource>
    {
        template <typename D> using type = consume_Windows_Media_Casting_ICastingSource<D>;
    };
}
#endif
