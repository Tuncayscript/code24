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
#ifndef LLM_OS_Devices_Scanners_0_H
#define LLM_OS_Devices_Scanners_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    template <typename TResult, typename TProgress> struct __declspec(empty_bases) IAsyncOperationWithProgress;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    struct Rect;
    struct Size;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm::OS::Graphics::Printing
{
    enum class PrintMediaSize : int32_t;
    enum class PrintOrientation : int32_t;
}
LLM_EXPORT namespace llm::OS::Storage
{
    struct StorageFile;
    struct StorageFolder;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct IRandomAccessStream;
}
LLM_EXPORT namespace llm::OS::Devices::Scanners
{
    enum class ImageScannerAutoCroppingMode : int32_t
    {
        Disabled = 0,
        SingleRegion = 1,
        MultipleRegion = 2,
    };
    enum class ImageScannerColorMode : int32_t
    {
        Color = 0,
        Grayscale = 1,
        Monochrome = 2,
        AutoColor = 3,
    };
    enum class ImageScannerFormat : int32_t
    {
        Jpeg = 0,
        Png = 1,
        DeviceIndependentBitmap = 2,
        Tiff = 3,
        Xps = 4,
        OpenXps = 5,
        Pdf = 6,
    };
    enum class ImageScannerScanSource : int32_t
    {
        Default = 0,
        Flatbed = 1,
        Feeder = 2,
        AutoConfigured = 3,
    };
    struct IImageScanner;
    struct IImageScannerFeederConfiguration;
    struct IImageScannerFormatConfiguration;
    struct IImageScannerPreviewResult;
    struct IImageScannerScanResult;
    struct IImageScannerSourceConfiguration;
    struct IImageScannerStatics;
    struct ImageScanner;
    struct ImageScannerAutoConfiguration;
    struct ImageScannerFeederConfiguration;
    struct ImageScannerFlatbedConfiguration;
    struct ImageScannerPreviewResult;
    struct ImageScannerScanResult;
    struct ImageScannerResolution;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::Scanners::IImageScanner>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Scanners::IImageScannerFeederConfiguration>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Scanners::IImageScannerFormatConfiguration>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Scanners::IImageScannerPreviewResult>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Scanners::IImageScannerScanResult>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Scanners::IImageScannerSourceConfiguration>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Scanners::IImageScannerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Scanners::ImageScanner>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Scanners::ImageScannerAutoConfiguration>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Scanners::ImageScannerFeederConfiguration>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Scanners::ImageScannerFlatbedConfiguration>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Scanners::ImageScannerPreviewResult>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Scanners::ImageScannerScanResult>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Scanners::ImageScannerAutoCroppingMode>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Scanners::ImageScannerColorMode>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Scanners::ImageScannerFormat>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Scanners::ImageScannerScanSource>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Scanners::ImageScannerResolution>{ using type = struct_category<float, float>; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::ImageScanner> = L"Windows.Devices.Scanners.ImageScanner";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::ImageScannerAutoConfiguration> = L"Windows.Devices.Scanners.ImageScannerAutoConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::ImageScannerFeederConfiguration> = L"Windows.Devices.Scanners.ImageScannerFeederConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::ImageScannerFlatbedConfiguration> = L"Windows.Devices.Scanners.ImageScannerFlatbedConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::ImageScannerPreviewResult> = L"Windows.Devices.Scanners.ImageScannerPreviewResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::ImageScannerScanResult> = L"Windows.Devices.Scanners.ImageScannerScanResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::ImageScannerAutoCroppingMode> = L"Windows.Devices.Scanners.ImageScannerAutoCroppingMode";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::ImageScannerColorMode> = L"Windows.Devices.Scanners.ImageScannerColorMode";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::ImageScannerFormat> = L"Windows.Devices.Scanners.ImageScannerFormat";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::ImageScannerScanSource> = L"Windows.Devices.Scanners.ImageScannerScanSource";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::ImageScannerResolution> = L"Windows.Devices.Scanners.ImageScannerResolution";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::IImageScanner> = L"Windows.Devices.Scanners.IImageScanner";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::IImageScannerFeederConfiguration> = L"Windows.Devices.Scanners.IImageScannerFeederConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::IImageScannerFormatConfiguration> = L"Windows.Devices.Scanners.IImageScannerFormatConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::IImageScannerPreviewResult> = L"Windows.Devices.Scanners.IImageScannerPreviewResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::IImageScannerScanResult> = L"Windows.Devices.Scanners.IImageScannerScanResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::IImageScannerSourceConfiguration> = L"Windows.Devices.Scanners.IImageScannerSourceConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Scanners::IImageScannerStatics> = L"Windows.Devices.Scanners.IImageScannerStatics";
    template <> inline constexpr guid guid_v<llm::OS::Devices::Scanners::IImageScanner>{ 0x53A88F78,0x5298,0x48A0,{ 0x8D,0xA3,0x80,0x87,0x51,0x96,0x65,0xE0 } }; // 53A88F78-5298-48A0-8DA3-8087519665E0
    template <> inline constexpr guid guid_v<llm::OS::Devices::Scanners::IImageScannerFeederConfiguration>{ 0x74BDACEE,0xFA97,0x4C17,{ 0x82,0x80,0x40,0xE3,0x9C,0x6D,0xCC,0x67 } }; // 74BDACEE-FA97-4C17-8280-40E39C6DCC67
    template <> inline constexpr guid guid_v<llm::OS::Devices::Scanners::IImageScannerFormatConfiguration>{ 0xAE275D11,0xDADF,0x4010,{ 0xBF,0x10,0xCC,0xA5,0xC8,0x3D,0xCB,0xB0 } }; // AE275D11-DADF-4010-BF10-CCA5C83DCBB0
    template <> inline constexpr guid guid_v<llm::OS::Devices::Scanners::IImageScannerPreviewResult>{ 0x08B7FE8E,0x8891,0x441D,{ 0xBE,0x9C,0x17,0x6F,0xA1,0x09,0xC8,0xBB } }; // 08B7FE8E-8891-441D-BE9C-176FA109C8BB
    template <> inline constexpr guid guid_v<llm::OS::Devices::Scanners::IImageScannerScanResult>{ 0xC91624CD,0x9037,0x4E48,{ 0x84,0xC1,0xAC,0x09,0x75,0x07,0x6B,0xC5 } }; // C91624CD-9037-4E48-84C1-AC0975076BC5
    template <> inline constexpr guid guid_v<llm::OS::Devices::Scanners::IImageScannerSourceConfiguration>{ 0xBFB50055,0x0B44,0x4C82,{ 0x9E,0x89,0x20,0x5F,0x9C,0x23,0x4E,0x59 } }; // BFB50055-0B44-4C82-9E89-205F9C234E59
    template <> inline constexpr guid guid_v<llm::OS::Devices::Scanners::IImageScannerStatics>{ 0xBC57E70E,0xD804,0x4477,{ 0x9F,0xB5,0xB9,0x11,0xB5,0x47,0x38,0x97 } }; // BC57E70E-D804-4477-9FB5-B911B5473897
    template <> struct default_interface<llm::OS::Devices::Scanners::ImageScanner>{ using type = llm::OS::Devices::Scanners::IImageScanner; };
    template <> struct default_interface<llm::OS::Devices::Scanners::ImageScannerAutoConfiguration>{ using type = llm::OS::Devices::Scanners::IImageScannerFormatConfiguration; };
    template <> struct default_interface<llm::OS::Devices::Scanners::ImageScannerFeederConfiguration>{ using type = llm::OS::Devices::Scanners::IImageScannerFormatConfiguration; };
    template <> struct default_interface<llm::OS::Devices::Scanners::ImageScannerFlatbedConfiguration>{ using type = llm::OS::Devices::Scanners::IImageScannerFormatConfiguration; };
    template <> struct default_interface<llm::OS::Devices::Scanners::ImageScannerPreviewResult>{ using type = llm::OS::Devices::Scanners::IImageScannerPreviewResult; };
    template <> struct default_interface<llm::OS::Devices::Scanners::ImageScannerScanResult>{ using type = llm::OS::Devices::Scanners::IImageScannerScanResult; };
    template <> struct abi<llm::OS::Devices::Scanners::IImageScanner>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DeviceId(void**) noexcept = 0;
            virtual int32_t __stdcall get_DefaultScanSource(int32_t*) noexcept = 0;
            virtual int32_t __stdcall IsScanSourceSupported(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall get_FlatbedConfiguration(void**) noexcept = 0;
            virtual int32_t __stdcall get_FeederConfiguration(void**) noexcept = 0;
            virtual int32_t __stdcall get_AutoConfiguration(void**) noexcept = 0;
            virtual int32_t __stdcall IsPreviewSupported(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall ScanPreviewToStreamAsync(int32_t, void*, void**) noexcept = 0;
            virtual int32_t __stdcall ScanFilesToFolderAsync(int32_t, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Scanners::IImageScannerFeederConfiguration>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CanAutoDetectPageSize(bool*) noexcept = 0;
            virtual int32_t __stdcall get_AutoDetectPageSize(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AutoDetectPageSize(bool) noexcept = 0;
            virtual int32_t __stdcall get_PageSize(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_PageSize(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_PageOrientation(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_PageOrientation(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_PageSizeDimensions(llm::OS::Foundation::Size*) noexcept = 0;
            virtual int32_t __stdcall IsPageSizeSupported(int32_t, int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall get_MaxNumberOfPages(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_MaxNumberOfPages(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_CanScanDuplex(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Duplex(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Duplex(bool) noexcept = 0;
            virtual int32_t __stdcall get_CanScanAhead(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ScanAhead(bool*) noexcept = 0;
            virtual int32_t __stdcall put_ScanAhead(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Scanners::IImageScannerFormatConfiguration>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DefaultFormat(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Format(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Format(int32_t) noexcept = 0;
            virtual int32_t __stdcall IsFormatSupported(int32_t, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Scanners::IImageScannerPreviewResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Succeeded(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Format(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Scanners::IImageScannerScanResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ScannedFiles(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Scanners::IImageScannerSourceConfiguration>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MinScanArea(llm::OS::Foundation::Size*) noexcept = 0;
            virtual int32_t __stdcall get_MaxScanArea(llm::OS::Foundation::Size*) noexcept = 0;
            virtual int32_t __stdcall get_SelectedScanRegion(llm::OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall put_SelectedScanRegion(llm::OS::Foundation::Rect) noexcept = 0;
            virtual int32_t __stdcall get_AutoCroppingMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_AutoCroppingMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall IsAutoCroppingModeSupported(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall get_MinResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution*) noexcept = 0;
            virtual int32_t __stdcall get_MaxResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution*) noexcept = 0;
            virtual int32_t __stdcall get_OpticalResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution*) noexcept = 0;
            virtual int32_t __stdcall get_DesiredResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution*) noexcept = 0;
            virtual int32_t __stdcall put_DesiredResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution) noexcept = 0;
            virtual int32_t __stdcall get_ActualResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution*) noexcept = 0;
            virtual int32_t __stdcall get_DefaultColorMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ColorMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ColorMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall IsColorModeSupported(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall get_MinBrightness(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MaxBrightness(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_BrightnessStep(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_DefaultBrightness(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Brightness(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Brightness(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_MinContrast(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MaxContrast(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ContrastStep(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_DefaultContrast(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Contrast(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Contrast(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Scanners::IImageScannerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromIdAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetDeviceSelector(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Scanners_IImageScanner
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DeviceId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerScanSource) DefaultScanSource() const;
        LLM_IMPL_AUTO(bool) IsScanSourceSupported(llm::OS::Devices::Scanners::ImageScannerScanSource const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerFlatbedConfiguration) FlatbedConfiguration() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerFeederConfiguration) FeederConfiguration() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerAutoConfiguration) AutoConfiguration() const;
        LLM_IMPL_AUTO(bool) IsPreviewSupported(llm::OS::Devices::Scanners::ImageScannerScanSource const& scanSource) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Scanners::ImageScannerPreviewResult>) ScanPreviewToStreamAsync(llm::OS::Devices::Scanners::ImageScannerScanSource const& scanSource, llm::OS::Storage::Streams::IRandomAccessStream const& targetStream) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Devices::Scanners::ImageScannerScanResult, uint32_t>) ScanFilesToFolderAsync(llm::OS::Devices::Scanners::ImageScannerScanSource const& scanSource, llm::OS::Storage::StorageFolder const& storageFolder) const;
    };
    template <> struct consume<llm::OS::Devices::Scanners::IImageScanner>
    {
        template <typename D> using type = consume_Windows_Devices_Scanners_IImageScanner<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) CanAutoDetectPageSize() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AutoDetectPageSize() const;
        LLM_IMPL_AUTO(void) AutoDetectPageSize(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Graphics::Printing::PrintMediaSize) PageSize() const;
        LLM_IMPL_AUTO(void) PageSize(llm::OS::Graphics::Printing::PrintMediaSize const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Graphics::Printing::PrintOrientation) PageOrientation() const;
        LLM_IMPL_AUTO(void) PageOrientation(llm::OS::Graphics::Printing::PrintOrientation const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Size) PageSizeDimensions() const;
        LLM_IMPL_AUTO(bool) IsPageSizeSupported(llm::OS::Graphics::Printing::PrintMediaSize const& pageSize, llm::OS::Graphics::Printing::PrintOrientation const& pageOrientation) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) MaxNumberOfPages() const;
        LLM_IMPL_AUTO(void) MaxNumberOfPages(uint32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) CanScanDuplex() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Duplex() const;
        LLM_IMPL_AUTO(void) Duplex(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) CanScanAhead() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) ScanAhead() const;
        LLM_IMPL_AUTO(void) ScanAhead(bool value) const;
    };
    template <> struct consume<llm::OS::Devices::Scanners::IImageScannerFeederConfiguration>
    {
        template <typename D> using type = consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Scanners_IImageScannerFormatConfiguration
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerFormat) DefaultFormat() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerFormat) Format() const;
        LLM_IMPL_AUTO(void) Format(llm::OS::Devices::Scanners::ImageScannerFormat const& value) const;
        LLM_IMPL_AUTO(bool) IsFormatSupported(llm::OS::Devices::Scanners::ImageScannerFormat const& value) const;
    };
    template <> struct consume<llm::OS::Devices::Scanners::IImageScannerFormatConfiguration>
    {
        template <typename D> using type = consume_Windows_Devices_Scanners_IImageScannerFormatConfiguration<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Scanners_IImageScannerPreviewResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Succeeded() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerFormat) Format() const;
    };
    template <> struct consume<llm::OS::Devices::Scanners::IImageScannerPreviewResult>
    {
        template <typename D> using type = consume_Windows_Devices_Scanners_IImageScannerPreviewResult<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Scanners_IImageScannerScanResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>) ScannedFiles() const;
    };
    template <> struct consume<llm::OS::Devices::Scanners::IImageScannerScanResult>
    {
        template <typename D> using type = consume_Windows_Devices_Scanners_IImageScannerScanResult<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Size) MinScanArea() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Size) MaxScanArea() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Rect) SelectedScanRegion() const;
        LLM_IMPL_AUTO(void) SelectedScanRegion(llm::OS::Foundation::Rect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerAutoCroppingMode) AutoCroppingMode() const;
        LLM_IMPL_AUTO(void) AutoCroppingMode(llm::OS::Devices::Scanners::ImageScannerAutoCroppingMode const& value) const;
        LLM_IMPL_AUTO(bool) IsAutoCroppingModeSupported(llm::OS::Devices::Scanners::ImageScannerAutoCroppingMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerResolution) MinResolution() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerResolution) MaxResolution() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerResolution) OpticalResolution() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerResolution) DesiredResolution() const;
        LLM_IMPL_AUTO(void) DesiredResolution(llm::OS::Devices::Scanners::ImageScannerResolution const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerResolution) ActualResolution() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerColorMode) DefaultColorMode() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerColorMode) ColorMode() const;
        LLM_IMPL_AUTO(void) ColorMode(llm::OS::Devices::Scanners::ImageScannerColorMode const& value) const;
        LLM_IMPL_AUTO(bool) IsColorModeSupported(llm::OS::Devices::Scanners::ImageScannerColorMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MinBrightness() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MaxBrightness() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) BrightnessStep() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) DefaultBrightness() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Brightness() const;
        LLM_IMPL_AUTO(void) Brightness(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MinContrast() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MaxContrast() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) ContrastStep() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) DefaultContrast() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Contrast() const;
        LLM_IMPL_AUTO(void) Contrast(int32_t value) const;
    };
    template <> struct consume<llm::OS::Devices::Scanners::IImageScannerSourceConfiguration>
    {
        template <typename D> using type = consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Scanners_IImageScannerStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Scanners::ImageScanner>) FromIdAsync(param::hstring const& deviceId) const;
        LLM_IMPL_AUTO(hstring) GetDeviceSelector() const;
    };
    template <> struct consume<llm::OS::Devices::Scanners::IImageScannerStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Scanners_IImageScannerStatics<D>;
    };
    struct struct_Windows_Devices_Scanners_ImageScannerResolution
    {
        float DpiX;
        float DpiY;
    };
    template <> struct abi<Windows::Devices::Scanners::ImageScannerResolution>
    {
        using type = struct_Windows_Devices_Scanners_ImageScannerResolution;
    };
}
#endif
