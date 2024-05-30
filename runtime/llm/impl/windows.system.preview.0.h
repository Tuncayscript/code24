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
#ifndef LLM_OS_System_Preview_0_H
#define LLM_OS_System_Preview_0_H
LLM_EXPORT namespace llm:OS::Devices::Sensors
{
    enum class SimpleOrientation : int32_t;
}
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::System::Preview
{
    enum class HingeState : int32_t
    {
        Unknown = 0,
        Closed = 1,
        Concave = 2,
        Flat = 3,
        Convex = 4,
        Full = 5,
    };
    struct ITwoPanelHingedDevicePosturePreview;
    struct ITwoPanelHingedDevicePosturePreviewReading;
    struct ITwoPanelHingedDevicePosturePreviewReadingChangedEventArgs;
    struct ITwoPanelHingedDevicePosturePreviewStatics;
    struct TwoPanelHingedDevicePosturePreview;
    struct TwoPanelHingedDevicePosturePreviewReading;
    struct TwoPanelHingedDevicePosturePreviewReadingChangedEventArgs;
}
namespace llm::impl
{
    template <> struct category<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreview>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewReading>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewReadingChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Preview::TwoPanelHingedDevicePosturePreview>{ using type = class_category; };
    template <> struct category<llm:OS::System::Preview::TwoPanelHingedDevicePosturePreviewReading>{ using type = class_category; };
    template <> struct category<llm:OS::System::Preview::TwoPanelHingedDevicePosturePreviewReadingChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::System::Preview::HingeState>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::System::Preview::TwoPanelHingedDevicePosturePreview> = L"Windows.System.Preview.TwoPanelHingedDevicePosturePreview";
    template <> inline constexpr auto& name_v<llm:OS::System::Preview::TwoPanelHingedDevicePosturePreviewReading> = L"Windows.System.Preview.TwoPanelHingedDevicePosturePreviewReading";
    template <> inline constexpr auto& name_v<llm:OS::System::Preview::TwoPanelHingedDevicePosturePreviewReadingChangedEventArgs> = L"Windows.System.Preview.TwoPanelHingedDevicePosturePreviewReadingChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::Preview::HingeState> = L"Windows.System.Preview.HingeState";
    template <> inline constexpr auto& name_v<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreview> = L"Windows.System.Preview.ITwoPanelHingedDevicePosturePreview";
    template <> inline constexpr auto& name_v<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewReading> = L"Windows.System.Preview.ITwoPanelHingedDevicePosturePreviewReading";
    template <> inline constexpr auto& name_v<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewReadingChangedEventArgs> = L"Windows.System.Preview.ITwoPanelHingedDevicePosturePreviewReadingChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewStatics> = L"Windows.System.Preview.ITwoPanelHingedDevicePosturePreviewStatics";
    template <> inline constexpr guid guid_v<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreview>{ 0x72245C31,0x4B39,0x42A6,{ 0x8E,0x73,0x72,0x35,0xAD,0xE1,0x68,0x53 } }; // 72245C31-4B39-42A6-8E73-7235ADE16853
    template <> inline constexpr guid guid_v<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewReading>{ 0xA0251452,0x4AD6,0x4B38,{ 0x84,0x26,0xC5,0x9A,0x15,0x49,0x3A,0x7D } }; // A0251452-4AD6-4B38-8426-C59A15493A7D
    template <> inline constexpr guid guid_v<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewReadingChangedEventArgs>{ 0x2D2D1BC6,0x02CE,0x474A,{ 0xA5,0x56,0xA7,0x5B,0x1C,0xF9,0x3A,0x03 } }; // 2D2D1BC6-02CE-474A-A556-A75B1CF93A03
    template <> inline constexpr guid guid_v<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewStatics>{ 0x0C4733D2,0x57E0,0x4180,{ 0xBD,0x5E,0xF3,0x1A,0x21,0x38,0x42,0x3E } }; // 0C4733D2-57E0-4180-BD5E-F31A2138423E
    template <> struct default_interface<llm:OS::System::Preview::TwoPanelHingedDevicePosturePreview>{ using type = llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreview; };
    template <> struct default_interface<llm:OS::System::Preview::TwoPanelHingedDevicePosturePreviewReading>{ using type = llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewReading; };
    template <> struct default_interface<llm:OS::System::Preview::TwoPanelHingedDevicePosturePreviewReadingChangedEventArgs>{ using type = llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewReadingChangedEventArgs; };
    template <> struct abi<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreview>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetCurrentPostureAsync(void**) noexcept = 0;
            virtual int32_t __stdcall add_PostureChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PostureChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewReading>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Timestamp(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_HingeState(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Panel1Orientation(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Panel1Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_Panel2Orientation(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Panel2Id(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewReadingChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Reading(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefaultAsync(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_System_Preview_ITwoPanelHingedDevicePosturePreview
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::Preview::TwoPanelHingedDevicePosturePreviewReading>) GetCurrentPostureAsync() const;
        LLM_IMPL_AUTO(llm::event_token) PostureChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::System::Preview::TwoPanelHingedDevicePosturePreview, llm:OS::System::Preview::TwoPanelHingedDevicePosturePreviewReadingChangedEventArgs> const& handler) const;
        using PostureChanged_revoker = impl::event_revoker<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreview, &impl::abi_t<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreview>::remove_PostureChanged>;
        [[nodiscard]] PostureChanged_revoker PostureChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::Preview::TwoPanelHingedDevicePosturePreview, llm:OS::System::Preview::TwoPanelHingedDevicePosturePreviewReadingChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PostureChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreview>
    {
        template <typename D> using type = consume_Windows_System_Preview_ITwoPanelHingedDevicePosturePreview<D>;
    };
    template <typename D>
    struct consume_Windows_System_Preview_ITwoPanelHingedDevicePosturePreviewReading
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::DateTime) Timestamp() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::Preview::HingeState) HingeState() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Devices::Sensors::SimpleOrientation) Panel1Orientation() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Panel1Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Devices::Sensors::SimpleOrientation) Panel2Orientation() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Panel2Id() const;
    };
    template <> struct consume<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewReading>
    {
        template <typename D> using type = consume_Windows_System_Preview_ITwoPanelHingedDevicePosturePreviewReading<D>;
    };
    template <typename D>
    struct consume_Windows_System_Preview_ITwoPanelHingedDevicePosturePreviewReadingChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::Preview::TwoPanelHingedDevicePosturePreviewReading) Reading() const;
    };
    template <> struct consume<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewReadingChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_System_Preview_ITwoPanelHingedDevicePosturePreviewReadingChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_System_Preview_ITwoPanelHingedDevicePosturePreviewStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::System::Preview::TwoPanelHingedDevicePosturePreview>) GetDefaultAsync() const;
    };
    template <> struct consume<llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewStatics>
    {
        template <typename D> using type = consume_Windows_System_Preview_ITwoPanelHingedDevicePosturePreviewStatics<D>;
    };
}
#endif
