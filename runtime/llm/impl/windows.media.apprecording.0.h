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
#ifndef LLM_OS_Media_AppRecording_0_H
#define LLM_OS_Media_AppRecording_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct HResult;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Storage
{
    struct StorageFile;
    struct StorageFolder;
}
LLM_EXPORT namespace llm:OS::Media::AppRecording
{
    enum class AppRecordingSaveScreenshotOption : int32_t
    {
        None = 0,
        HdrContentVisible = 1,
    };
    struct IAppRecordingManager;
    struct IAppRecordingManagerStatics;
    struct IAppRecordingResult;
    struct IAppRecordingSaveScreenshotResult;
    struct IAppRecordingSavedScreenshotInfo;
    struct IAppRecordingStatus;
    struct IAppRecordingStatusDetails;
    struct AppRecordingManager;
    struct AppRecordingResult;
    struct AppRecordingSaveScreenshotResult;
    struct AppRecordingSavedScreenshotInfo;
    struct AppRecordingStatus;
    struct AppRecordingStatusDetails;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::AppRecording::IAppRecordingManager>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::AppRecording::IAppRecordingManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::AppRecording::IAppRecordingResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::AppRecording::IAppRecordingSaveScreenshotResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::AppRecording::IAppRecordingSavedScreenshotInfo>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::AppRecording::IAppRecordingStatus>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::AppRecording::IAppRecordingStatusDetails>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::AppRecording::AppRecordingManager>{ using type = class_category; };
    template <> struct category<llm:OS::Media::AppRecording::AppRecordingResult>{ using type = class_category; };
    template <> struct category<llm:OS::Media::AppRecording::AppRecordingSaveScreenshotResult>{ using type = class_category; };
    template <> struct category<llm:OS::Media::AppRecording::AppRecordingSavedScreenshotInfo>{ using type = class_category; };
    template <> struct category<llm:OS::Media::AppRecording::AppRecordingStatus>{ using type = class_category; };
    template <> struct category<llm:OS::Media::AppRecording::AppRecordingStatusDetails>{ using type = class_category; };
    template <> struct category<llm:OS::Media::AppRecording::AppRecordingSaveScreenshotOption>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::AppRecording::AppRecordingManager> = L"Windows.Media.AppRecording.AppRecordingManager";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppRecording::AppRecordingResult> = L"Windows.Media.AppRecording.AppRecordingResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppRecording::AppRecordingSaveScreenshotResult> = L"Windows.Media.AppRecording.AppRecordingSaveScreenshotResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppRecording::AppRecordingSavedScreenshotInfo> = L"Windows.Media.AppRecording.AppRecordingSavedScreenshotInfo";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppRecording::AppRecordingStatus> = L"Windows.Media.AppRecording.AppRecordingStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppRecording::AppRecordingStatusDetails> = L"Windows.Media.AppRecording.AppRecordingStatusDetails";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppRecording::AppRecordingSaveScreenshotOption> = L"Windows.Media.AppRecording.AppRecordingSaveScreenshotOption";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppRecording::IAppRecordingManager> = L"Windows.Media.AppRecording.IAppRecordingManager";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppRecording::IAppRecordingManagerStatics> = L"Windows.Media.AppRecording.IAppRecordingManagerStatics";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppRecording::IAppRecordingResult> = L"Windows.Media.AppRecording.IAppRecordingResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppRecording::IAppRecordingSaveScreenshotResult> = L"Windows.Media.AppRecording.IAppRecordingSaveScreenshotResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppRecording::IAppRecordingSavedScreenshotInfo> = L"Windows.Media.AppRecording.IAppRecordingSavedScreenshotInfo";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppRecording::IAppRecordingStatus> = L"Windows.Media.AppRecording.IAppRecordingStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::AppRecording::IAppRecordingStatusDetails> = L"Windows.Media.AppRecording.IAppRecordingStatusDetails";
    template <> inline constexpr guid guid_v<llm:OS::Media::AppRecording::IAppRecordingManager>{ 0xE7E26076,0xA044,0x48E2,{ 0xA5,0x12,0x30,0x94,0xD5,0x74,0xC7,0xCC } }; // E7E26076-A044-48E2-A512-3094D574C7CC
    template <> inline constexpr guid guid_v<llm:OS::Media::AppRecording::IAppRecordingManagerStatics>{ 0x50E709F7,0x38CE,0x4BD3,{ 0x9D,0xB2,0xE7,0x2B,0xBE,0x9D,0xE1,0x1D } }; // 50E709F7-38CE-4BD3-9DB2-E72BBE9DE11D
    template <> inline constexpr guid guid_v<llm:OS::Media::AppRecording::IAppRecordingResult>{ 0x3A900864,0xC66D,0x46F9,{ 0xB2,0xD9,0x5B,0xC2,0xDA,0xD0,0x70,0xD7 } }; // 3A900864-C66D-46F9-B2D9-5BC2DAD070D7
    template <> inline constexpr guid guid_v<llm:OS::Media::AppRecording::IAppRecordingSaveScreenshotResult>{ 0x9C5B8D0A,0x0ABB,0x4457,{ 0xAA,0xEE,0x24,0xF9,0xC1,0x2E,0xC7,0x78 } }; // 9C5B8D0A-0ABB-4457-AAEE-24F9C12EC778
    template <> inline constexpr guid guid_v<llm:OS::Media::AppRecording::IAppRecordingSavedScreenshotInfo>{ 0x9B642D0A,0x189A,0x4D00,{ 0xBF,0x25,0xE1,0xBB,0x12,0x49,0xD5,0x94 } }; // 9B642D0A-189A-4D00-BF25-E1BB1249D594
    template <> inline constexpr guid guid_v<llm:OS::Media::AppRecording::IAppRecordingStatus>{ 0x1D0CC82C,0xBC18,0x4B8A,{ 0xA6,0xEF,0x12,0x7E,0xFA,0xB3,0xB5,0xD9 } }; // 1D0CC82C-BC18-4B8A-A6EF-127EFAB3B5D9
    template <> inline constexpr guid guid_v<llm:OS::Media::AppRecording::IAppRecordingStatusDetails>{ 0xB538A9B0,0x14ED,0x4412,{ 0xAC,0x45,0x6D,0x67,0x2C,0x9C,0x99,0x49 } }; // B538A9B0-14ED-4412-AC45-6D672C9C9949
    template <> struct default_interface<llm:OS::Media::AppRecording::AppRecordingManager>{ using type = llm:OS::Media::AppRecording::IAppRecordingManager; };
    template <> struct default_interface<llm:OS::Media::AppRecording::AppRecordingResult>{ using type = llm:OS::Media::AppRecording::IAppRecordingResult; };
    template <> struct default_interface<llm:OS::Media::AppRecording::AppRecordingSaveScreenshotResult>{ using type = llm:OS::Media::AppRecording::IAppRecordingSaveScreenshotResult; };
    template <> struct default_interface<llm:OS::Media::AppRecording::AppRecordingSavedScreenshotInfo>{ using type = llm:OS::Media::AppRecording::IAppRecordingSavedScreenshotInfo; };
    template <> struct default_interface<llm:OS::Media::AppRecording::AppRecordingStatus>{ using type = llm:OS::Media::AppRecording::IAppRecordingStatus; };
    template <> struct default_interface<llm:OS::Media::AppRecording::AppRecordingStatusDetails>{ using type = llm:OS::Media::AppRecording::IAppRecordingStatusDetails; };
    template <> struct abi<llm:OS::Media::AppRecording::IAppRecordingManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetStatus(void**) noexcept = 0;
            virtual int32_t __stdcall StartRecordingToFileAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RecordTimeSpanToFileAsync(int64_t, int64_t, void*, void**) noexcept = 0;
            virtual int32_t __stdcall get_SupportedScreenshotMediaEncodingSubtypes(void**) noexcept = 0;
            virtual int32_t __stdcall SaveScreenshotToFilesAsync(void*, void*, int32_t, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::AppRecording::IAppRecordingManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::AppRecording::IAppRecordingResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Succeeded(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
            virtual int32_t __stdcall get_Duration(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_IsFileTruncated(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::AppRecording::IAppRecordingSaveScreenshotResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Succeeded(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
            virtual int32_t __stdcall get_SavedScreenshotInfos(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::AppRecording::IAppRecordingSavedScreenshotInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_File(void**) noexcept = 0;
            virtual int32_t __stdcall get_MediaEncodingSubtype(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::AppRecording::IAppRecordingStatus>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CanRecord(bool*) noexcept = 0;
            virtual int32_t __stdcall get_CanRecordTimeSpan(bool*) noexcept = 0;
            virtual int32_t __stdcall get_HistoricalBufferDuration(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Details(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::AppRecording::IAppRecordingStatusDetails>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsAnyAppBroadcasting(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsCaptureResourceUnavailable(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsGameStreamInProgress(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsTimeSpanRecordingDisabled(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsGpuConstrained(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsAppInactive(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsBlockedForApp(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsDisabledByUser(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsDisabledBySystem(bool*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_AppRecording_IAppRecordingManager
    {
        LLM_IMPL_AUTO(llm:OS::Media::AppRecording::AppRecordingStatus) GetStatus() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::AppRecording::AppRecordingResult>) StartRecordingToFileAsync(llm:OS::Storage::StorageFile const& file) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::AppRecording::AppRecordingResult>) RecordTimeSpanToFileAsync(llm:OS::Foundation::DateTime const& startTime, llm:OS::Foundation::TimeSpan const& duration, llm:OS::Storage::StorageFile const& file) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<hstring>) SupportedScreenshotMediaEncodingSubtypes() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::AppRecording::AppRecordingSaveScreenshotResult>) SaveScreenshotToFilesAsync(llm:OS::Storage::StorageFolder const& folder, param::hstring const& filenamePrefix, llm:OS::Media::AppRecording::AppRecordingSaveScreenshotOption const& option, param::async_iterable<hstring> const& requestedFormats) const;
    };
    template <> struct consume<llm:OS::Media::AppRecording::IAppRecordingManager>
    {
        template <typename D> using type = consume_Windows_Media_AppRecording_IAppRecordingManager<D>;
    };
    template <typename D>
    struct consume_Windows_Media_AppRecording_IAppRecordingManagerStatics
    {
        LLM_IMPL_AUTO(llm:OS::Media::AppRecording::AppRecordingManager) GetDefault() const;
    };
    template <> struct consume<llm:OS::Media::AppRecording::IAppRecordingManagerStatics>
    {
        template <typename D> using type = consume_Windows_Media_AppRecording_IAppRecordingManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Media_AppRecording_IAppRecordingResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Succeeded() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) Duration() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsFileTruncated() const;
    };
    template <> struct consume<llm:OS::Media::AppRecording::IAppRecordingResult>
    {
        template <typename D> using type = consume_Windows_Media_AppRecording_IAppRecordingResult<D>;
    };
    template <typename D>
    struct consume_Windows_Media_AppRecording_IAppRecordingSaveScreenshotResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Succeeded() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::AppRecording::AppRecordingSavedScreenshotInfo>) SavedScreenshotInfos() const;
    };
    template <> struct consume<llm:OS::Media::AppRecording::IAppRecordingSaveScreenshotResult>
    {
        template <typename D> using type = consume_Windows_Media_AppRecording_IAppRecordingSaveScreenshotResult<D>;
    };
    template <typename D>
    struct consume_Windows_Media_AppRecording_IAppRecordingSavedScreenshotInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::StorageFile) File() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) MediaEncodingSubtype() const;
    };
    template <> struct consume<llm:OS::Media::AppRecording::IAppRecordingSavedScreenshotInfo>
    {
        template <typename D> using type = consume_Windows_Media_AppRecording_IAppRecordingSavedScreenshotInfo<D>;
    };
    template <typename D>
    struct consume_Windows_Media_AppRecording_IAppRecordingStatus
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) CanRecord() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) CanRecordTimeSpan() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) HistoricalBufferDuration() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::AppRecording::AppRecordingStatusDetails) Details() const;
    };
    template <> struct consume<llm:OS::Media::AppRecording::IAppRecordingStatus>
    {
        template <typename D> using type = consume_Windows_Media_AppRecording_IAppRecordingStatus<D>;
    };
    template <typename D>
    struct consume_Windows_Media_AppRecording_IAppRecordingStatusDetails
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsAnyAppBroadcasting() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsCaptureResourceUnavailable() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsGameStreamInProgress() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsTimeSpanRecordingDisabled() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsGpuConstrained() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsAppInactive() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsBlockedForApp() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsDisabledByUser() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsDisabledBySystem() const;
    };
    template <> struct consume<llm:OS::Media::AppRecording::IAppRecordingStatusDetails>
    {
        template <typename D> using type = consume_Windows_Media_AppRecording_IAppRecordingStatusDetails<D>;
    };
}
#endif
