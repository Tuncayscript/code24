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
#ifndef LLM_OS_Media_Capture_Core_0_H
#define LLM_OS_Media_Capture_Core_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename T> struct __declspec(empty_bases) IReference;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Media::Capture
{
    struct CapturedFrame;
    struct CapturedFrameControlValues;
}
LLM_EXPORT namespace llm:OS::Media::Capture::Core
{
    struct IVariablePhotoCapturedEventArgs;
    struct IVariablePhotoSequenceCapture;
    struct IVariablePhotoSequenceCapture2;
    struct VariablePhotoCapturedEventArgs;
    struct VariablePhotoSequenceCapture;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::Capture::Core::IVariablePhotoCapturedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Capture::Core::IVariablePhotoSequenceCapture>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Capture::Core::IVariablePhotoSequenceCapture2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Capture::Core::VariablePhotoCapturedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Capture::Core::VariablePhotoSequenceCapture>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::Capture::Core::VariablePhotoCapturedEventArgs> = L"Windows.Media.Capture.Core.VariablePhotoCapturedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Capture::Core::VariablePhotoSequenceCapture> = L"Windows.Media.Capture.Core.VariablePhotoSequenceCapture";
    template <> inline constexpr auto& name_v<llm:OS::Media::Capture::Core::IVariablePhotoCapturedEventArgs> = L"Windows.Media.Capture.Core.IVariablePhotoCapturedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Capture::Core::IVariablePhotoSequenceCapture> = L"Windows.Media.Capture.Core.IVariablePhotoSequenceCapture";
    template <> inline constexpr auto& name_v<llm:OS::Media::Capture::Core::IVariablePhotoSequenceCapture2> = L"Windows.Media.Capture.Core.IVariablePhotoSequenceCapture2";
    template <> inline constexpr guid guid_v<llm:OS::Media::Capture::Core::IVariablePhotoCapturedEventArgs>{ 0xD1EB4C5C,0x1B53,0x4E4A,{ 0x8B,0x5C,0xDB,0x78,0x87,0xAC,0x94,0x9B } }; // D1EB4C5C-1B53-4E4A-8B5C-DB7887AC949B
    template <> inline constexpr guid guid_v<llm:OS::Media::Capture::Core::IVariablePhotoSequenceCapture>{ 0xD0112D1D,0x031E,0x4041,{ 0xA6,0xD6,0xBD,0x74,0x24,0x76,0xA8,0xEE } }; // D0112D1D-031E-4041-A6D6-BD742476A8EE
    template <> inline constexpr guid guid_v<llm:OS::Media::Capture::Core::IVariablePhotoSequenceCapture2>{ 0xFE2C62BC,0x50B0,0x43E3,{ 0x91,0x7C,0xE3,0xB9,0x27,0x98,0x94,0x2F } }; // FE2C62BC-50B0-43E3-917C-E3B92798942F
    template <> struct default_interface<llm:OS::Media::Capture::Core::VariablePhotoCapturedEventArgs>{ using type = llm:OS::Media::Capture::Core::IVariablePhotoCapturedEventArgs; };
    template <> struct default_interface<llm:OS::Media::Capture::Core::VariablePhotoSequenceCapture>{ using type = llm:OS::Media::Capture::Core::IVariablePhotoSequenceCapture; };
    template <> struct abi<llm:OS::Media::Capture::Core::IVariablePhotoCapturedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Frame(void**) noexcept = 0;
            virtual int32_t __stdcall get_CaptureTimeOffset(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_UsedFrameControllerIndex(void**) noexcept = 0;
            virtual int32_t __stdcall get_CapturedFrameControlValues(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Capture::Core::IVariablePhotoSequenceCapture>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall StartAsync(void**) noexcept = 0;
            virtual int32_t __stdcall StopAsync(void**) noexcept = 0;
            virtual int32_t __stdcall FinishAsync(void**) noexcept = 0;
            virtual int32_t __stdcall add_PhotoCaptured(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PhotoCaptured(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Stopped(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Stopped(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Capture::Core::IVariablePhotoSequenceCapture2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall UpdateSettingsAsync(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_Capture_Core_IVariablePhotoCapturedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Capture::CapturedFrame) Frame() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) CaptureTimeOffset() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<uint32_t>) UsedFrameControllerIndex() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Capture::CapturedFrameControlValues) CapturedFrameControlValues() const;
    };
    template <> struct consume<llm:OS::Media::Capture::Core::IVariablePhotoCapturedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_Capture_Core_IVariablePhotoCapturedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Capture_Core_IVariablePhotoSequenceCapture
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) StartAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) StopAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) FinishAsync() const;
        LLM_IMPL_AUTO(llm::event_token) PhotoCaptured(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Capture::Core::VariablePhotoSequenceCapture, llm:OS::Media::Capture::Core::VariablePhotoCapturedEventArgs> const& handler) const;
        using PhotoCaptured_revoker = impl::event_revoker<llm:OS::Media::Capture::Core::IVariablePhotoSequenceCapture, &impl::abi_t<llm:OS::Media::Capture::Core::IVariablePhotoSequenceCapture>::remove_PhotoCaptured>;
        [[nodiscard]] PhotoCaptured_revoker PhotoCaptured(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Capture::Core::VariablePhotoSequenceCapture, llm:OS::Media::Capture::Core::VariablePhotoCapturedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PhotoCaptured(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Stopped(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Capture::Core::VariablePhotoSequenceCapture, llm:OS::Foundation::IInspectable> const& handler) const;
        using Stopped_revoker = impl::event_revoker<llm:OS::Media::Capture::Core::IVariablePhotoSequenceCapture, &impl::abi_t<llm:OS::Media::Capture::Core::IVariablePhotoSequenceCapture>::remove_Stopped>;
        [[nodiscard]] Stopped_revoker Stopped(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Capture::Core::VariablePhotoSequenceCapture, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Stopped(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Media::Capture::Core::IVariablePhotoSequenceCapture>
    {
        template <typename D> using type = consume_Windows_Media_Capture_Core_IVariablePhotoSequenceCapture<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Capture_Core_IVariablePhotoSequenceCapture2
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) UpdateSettingsAsync() const;
    };
    template <> struct consume<llm:OS::Media::Capture::Core::IVariablePhotoSequenceCapture2>
    {
        template <typename D> using type = consume_Windows_Media_Capture_Core_IVariablePhotoSequenceCapture2<D>;
    };
}
#endif
