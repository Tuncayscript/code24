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
#ifndef LLM_OS_Devices_Scanners_H
#define LLM_OS_Devices_Scanners_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Graphics.Printing.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Devices.Scanners.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Scanners_IImageScanner<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScanner)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerScanSource) consume_Windows_Devices_Scanners_IImageScanner<D>::DefaultScanSource() const
    {
        llm::OS::Devices::Scanners::ImageScannerScanSource value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScanner)->get_DefaultScanSource(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Scanners_IImageScanner<D>::IsScanSourceSupported(llm::OS::Devices::Scanners::ImageScannerScanSource const& value) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScanner)->IsScanSourceSupported(static_cast<int32_t>(value), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerFlatbedConfiguration) consume_Windows_Devices_Scanners_IImageScanner<D>::FlatbedConfiguration() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScanner)->get_FlatbedConfiguration(&value));
        return llm::OS::Devices::Scanners::ImageScannerFlatbedConfiguration{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerFeederConfiguration) consume_Windows_Devices_Scanners_IImageScanner<D>::FeederConfiguration() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScanner)->get_FeederConfiguration(&value));
        return llm::OS::Devices::Scanners::ImageScannerFeederConfiguration{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerAutoConfiguration) consume_Windows_Devices_Scanners_IImageScanner<D>::AutoConfiguration() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScanner)->get_AutoConfiguration(&value));
        return llm::OS::Devices::Scanners::ImageScannerAutoConfiguration{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Scanners_IImageScanner<D>::IsPreviewSupported(llm::OS::Devices::Scanners::ImageScannerScanSource const& scanSource) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScanner)->IsPreviewSupported(static_cast<int32_t>(scanSource), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Scanners::ImageScannerPreviewResult>) consume_Windows_Devices_Scanners_IImageScanner<D>::ScanPreviewToStreamAsync(llm::OS::Devices::Scanners::ImageScannerScanSource const& scanSource, llm::OS::Storage::Streams::IRandomAccessStream const& targetStream) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScanner)->ScanPreviewToStreamAsync(static_cast<int32_t>(scanSource), *(void**)(&targetStream), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Scanners::ImageScannerPreviewResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Devices::Scanners::ImageScannerScanResult, uint32_t>) consume_Windows_Devices_Scanners_IImageScanner<D>::ScanFilesToFolderAsync(llm::OS::Devices::Scanners::ImageScannerScanSource const& scanSource, llm::OS::Storage::StorageFolder const& storageFolder) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScanner)->ScanFilesToFolderAsync(static_cast<int32_t>(scanSource), *(void**)(&storageFolder), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Devices::Scanners::ImageScannerScanResult, uint32_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::CanAutoDetectPageSize() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFeederConfiguration)->get_CanAutoDetectPageSize(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::AutoDetectPageSize() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFeederConfiguration)->get_AutoDetectPageSize(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::AutoDetectPageSize(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFeederConfiguration)->put_AutoDetectPageSize(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing::PrintMediaSize) consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::PageSize() const
    {
        llm::OS::Graphics::Printing::PrintMediaSize value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFeederConfiguration)->get_PageSize(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::PageSize(llm::OS::Graphics::Printing::PrintMediaSize const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFeederConfiguration)->put_PageSize(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing::PrintOrientation) consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::PageOrientation() const
    {
        llm::OS::Graphics::Printing::PrintOrientation value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFeederConfiguration)->get_PageOrientation(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::PageOrientation(llm::OS::Graphics::Printing::PrintOrientation const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFeederConfiguration)->put_PageOrientation(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::PageSizeDimensions() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFeederConfiguration)->get_PageSizeDimensions(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::IsPageSizeSupported(llm::OS::Graphics::Printing::PrintMediaSize const& pageSize, llm::OS::Graphics::Printing::PrintOrientation const& pageOrientation) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFeederConfiguration)->IsPageSizeSupported(static_cast<int32_t>(pageSize), static_cast<int32_t>(pageOrientation), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::MaxNumberOfPages() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFeederConfiguration)->get_MaxNumberOfPages(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::MaxNumberOfPages(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFeederConfiguration)->put_MaxNumberOfPages(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::CanScanDuplex() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFeederConfiguration)->get_CanScanDuplex(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::Duplex() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFeederConfiguration)->get_Duplex(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::Duplex(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFeederConfiguration)->put_Duplex(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::CanScanAhead() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFeederConfiguration)->get_CanScanAhead(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::ScanAhead() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFeederConfiguration)->get_ScanAhead(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::ScanAhead(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFeederConfiguration)->put_ScanAhead(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerFormat) consume_Windows_Devices_Scanners_IImageScannerFormatConfiguration<D>::DefaultFormat() const
    {
        llm::OS::Devices::Scanners::ImageScannerFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFormatConfiguration)->get_DefaultFormat(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerFormat) consume_Windows_Devices_Scanners_IImageScannerFormatConfiguration<D>::Format() const
    {
        llm::OS::Devices::Scanners::ImageScannerFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFormatConfiguration)->get_Format(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Scanners_IImageScannerFormatConfiguration<D>::Format(llm::OS::Devices::Scanners::ImageScannerFormat const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFormatConfiguration)->put_Format(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Scanners_IImageScannerFormatConfiguration<D>::IsFormatSupported(llm::OS::Devices::Scanners::ImageScannerFormat const& value) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerFormatConfiguration)->IsFormatSupported(static_cast<int32_t>(value), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Scanners_IImageScannerPreviewResult<D>::Succeeded() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerPreviewResult)->get_Succeeded(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerFormat) consume_Windows_Devices_Scanners_IImageScannerPreviewResult<D>::Format() const
    {
        llm::OS::Devices::Scanners::ImageScannerFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerPreviewResult)->get_Format(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>) consume_Windows_Devices_Scanners_IImageScannerScanResult<D>::ScannedFiles() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerScanResult)->get_ScannedFiles(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::MinScanArea() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_MinScanArea(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::MaxScanArea() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_MaxScanArea(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::SelectedScanRegion() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_SelectedScanRegion(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::SelectedScanRegion(llm::OS::Foundation::Rect const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->put_SelectedScanRegion(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerAutoCroppingMode) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::AutoCroppingMode() const
    {
        llm::OS::Devices::Scanners::ImageScannerAutoCroppingMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_AutoCroppingMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::AutoCroppingMode(llm::OS::Devices::Scanners::ImageScannerAutoCroppingMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->put_AutoCroppingMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::IsAutoCroppingModeSupported(llm::OS::Devices::Scanners::ImageScannerAutoCroppingMode const& value) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->IsAutoCroppingModeSupported(static_cast<int32_t>(value), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerResolution) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::MinResolution() const
    {
        llm::OS::Devices::Scanners::ImageScannerResolution value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_MinResolution(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerResolution) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::MaxResolution() const
    {
        llm::OS::Devices::Scanners::ImageScannerResolution value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_MaxResolution(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerResolution) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::OpticalResolution() const
    {
        llm::OS::Devices::Scanners::ImageScannerResolution value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_OpticalResolution(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerResolution) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::DesiredResolution() const
    {
        llm::OS::Devices::Scanners::ImageScannerResolution value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_DesiredResolution(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::DesiredResolution(llm::OS::Devices::Scanners::ImageScannerResolution const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->put_DesiredResolution(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerResolution) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::ActualResolution() const
    {
        llm::OS::Devices::Scanners::ImageScannerResolution value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_ActualResolution(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerColorMode) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::DefaultColorMode() const
    {
        llm::OS::Devices::Scanners::ImageScannerColorMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_DefaultColorMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Scanners::ImageScannerColorMode) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::ColorMode() const
    {
        llm::OS::Devices::Scanners::ImageScannerColorMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_ColorMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::ColorMode(llm::OS::Devices::Scanners::ImageScannerColorMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->put_ColorMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::IsColorModeSupported(llm::OS::Devices::Scanners::ImageScannerColorMode const& value) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->IsColorModeSupported(static_cast<int32_t>(value), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::MinBrightness() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_MinBrightness(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::MaxBrightness() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_MaxBrightness(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::BrightnessStep() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_BrightnessStep(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::DefaultBrightness() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_DefaultBrightness(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::Brightness() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_Brightness(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::Brightness(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->put_Brightness(value));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::MinContrast() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_MinContrast(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::MaxContrast() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_MaxContrast(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::ContrastStep() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_ContrastStep(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::DefaultContrast() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_DefaultContrast(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::Contrast() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->get_Contrast(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::Contrast(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerSourceConfiguration)->put_Contrast(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Scanners::ImageScanner>) consume_Windows_Devices_Scanners_IImageScannerStatics<D>::FromIdAsync(param::hstring const& deviceId) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerStatics)->FromIdAsync(*(void**)(&deviceId), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Scanners::ImageScanner>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Scanners_IImageScannerStatics<D>::GetDeviceSelector() const
    {
        void* selector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Scanners::IImageScannerStatics)->GetDeviceSelector(&selector));
        return hstring{ selector, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Scanners::IImageScanner> : produce_base<D, llm::OS::Devices::Scanners::IImageScanner>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DefaultScanSource(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Scanners::ImageScannerScanSource>(this->shim().DefaultScanSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsScanSourceSupported(int32_t value, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsScanSourceSupported(*reinterpret_cast<llm::OS::Devices::Scanners::ImageScannerScanSource const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FlatbedConfiguration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Scanners::ImageScannerFlatbedConfiguration>(this->shim().FlatbedConfiguration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FeederConfiguration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Scanners::ImageScannerFeederConfiguration>(this->shim().FeederConfiguration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AutoConfiguration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Scanners::ImageScannerAutoConfiguration>(this->shim().AutoConfiguration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsPreviewSupported(int32_t scanSource, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsPreviewSupported(*reinterpret_cast<llm::OS::Devices::Scanners::ImageScannerScanSource const*>(&scanSource)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ScanPreviewToStreamAsync(int32_t scanSource, void* targetStream, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Scanners::ImageScannerPreviewResult>>(this->shim().ScanPreviewToStreamAsync(*reinterpret_cast<llm::OS::Devices::Scanners::ImageScannerScanSource const*>(&scanSource), *reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&targetStream)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ScanFilesToFolderAsync(int32_t scanSource, void* storageFolder, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Devices::Scanners::ImageScannerScanResult, uint32_t>>(this->shim().ScanFilesToFolderAsync(*reinterpret_cast<llm::OS::Devices::Scanners::ImageScannerScanSource const*>(&scanSource), *reinterpret_cast<llm::OS::Storage::StorageFolder const*>(&storageFolder)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Scanners::IImageScannerFeederConfiguration> : produce_base<D, llm::OS::Devices::Scanners::IImageScannerFeederConfiguration>
    {
        int32_t __stdcall get_CanAutoDetectPageSize(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanAutoDetectPageSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AutoDetectPageSize(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AutoDetectPageSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AutoDetectPageSize(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoDetectPageSize(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PageSize(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing::PrintMediaSize>(this->shim().PageSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PageSize(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PageSize(*reinterpret_cast<llm::OS::Graphics::Printing::PrintMediaSize const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PageOrientation(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing::PrintOrientation>(this->shim().PageOrientation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PageOrientation(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PageOrientation(*reinterpret_cast<llm::OS::Graphics::Printing::PrintOrientation const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PageSizeDimensions(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().PageSizeDimensions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsPageSizeSupported(int32_t pageSize, int32_t pageOrientation, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsPageSizeSupported(*reinterpret_cast<llm::OS::Graphics::Printing::PrintMediaSize const*>(&pageSize), *reinterpret_cast<llm::OS::Graphics::Printing::PrintOrientation const*>(&pageOrientation)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxNumberOfPages(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxNumberOfPages());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaxNumberOfPages(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxNumberOfPages(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanScanDuplex(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanScanDuplex());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Duplex(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Duplex());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Duplex(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Duplex(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanScanAhead(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanScanAhead());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ScanAhead(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ScanAhead());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ScanAhead(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScanAhead(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Devices::Scanners::IImageScannerFormatConfiguration> : produce_base<D, llm::OS::Devices::Scanners::IImageScannerFormatConfiguration>
    {
        int32_t __stdcall get_DefaultFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Scanners::ImageScannerFormat>(this->shim().DefaultFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Format(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Scanners::ImageScannerFormat>(this->shim().Format());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Format(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Format(*reinterpret_cast<llm::OS::Devices::Scanners::ImageScannerFormat const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsFormatSupported(int32_t value, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsFormatSupported(*reinterpret_cast<llm::OS::Devices::Scanners::ImageScannerFormat const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Scanners::IImageScannerPreviewResult> : produce_base<D, llm::OS::Devices::Scanners::IImageScannerPreviewResult>
    {
        int32_t __stdcall get_Succeeded(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Succeeded());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Format(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Scanners::ImageScannerFormat>(this->shim().Format());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Scanners::IImageScannerScanResult> : produce_base<D, llm::OS::Devices::Scanners::IImageScannerScanResult>
    {
        int32_t __stdcall get_ScannedFiles(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>>(this->shim().ScannedFiles());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Devices::Scanners::IImageScannerSourceConfiguration> : produce_base<D, llm::OS::Devices::Scanners::IImageScannerSourceConfiguration>
    {
        int32_t __stdcall get_MinScanArea(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().MinScanArea());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxScanArea(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().MaxScanArea());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectedScanRegion(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().SelectedScanRegion());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SelectedScanRegion(llm::OS::Foundation::Rect value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectedScanRegion(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AutoCroppingMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Scanners::ImageScannerAutoCroppingMode>(this->shim().AutoCroppingMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AutoCroppingMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoCroppingMode(*reinterpret_cast<llm::OS::Devices::Scanners::ImageScannerAutoCroppingMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsAutoCroppingModeSupported(int32_t value, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsAutoCroppingModeSupported(*reinterpret_cast<llm::OS::Devices::Scanners::ImageScannerAutoCroppingMode const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution* value) noexcept final try
        {
            zero_abi<llm::OS::Devices::Scanners::ImageScannerResolution>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Scanners::ImageScannerResolution>(this->shim().MinResolution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution* value) noexcept final try
        {
            zero_abi<llm::OS::Devices::Scanners::ImageScannerResolution>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Scanners::ImageScannerResolution>(this->shim().MaxResolution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OpticalResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution* value) noexcept final try
        {
            zero_abi<llm::OS::Devices::Scanners::ImageScannerResolution>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Scanners::ImageScannerResolution>(this->shim().OpticalResolution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DesiredResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution* value) noexcept final try
        {
            zero_abi<llm::OS::Devices::Scanners::ImageScannerResolution>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Scanners::ImageScannerResolution>(this->shim().DesiredResolution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DesiredResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredResolution(*reinterpret_cast<llm::OS::Devices::Scanners::ImageScannerResolution const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActualResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution* value) noexcept final try
        {
            zero_abi<llm::OS::Devices::Scanners::ImageScannerResolution>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Scanners::ImageScannerResolution>(this->shim().ActualResolution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DefaultColorMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Scanners::ImageScannerColorMode>(this->shim().DefaultColorMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ColorMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Scanners::ImageScannerColorMode>(this->shim().ColorMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ColorMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ColorMode(*reinterpret_cast<llm::OS::Devices::Scanners::ImageScannerColorMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsColorModeSupported(int32_t value, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsColorModeSupported(*reinterpret_cast<llm::OS::Devices::Scanners::ImageScannerColorMode const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinBrightness(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().MinBrightness());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxBrightness(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().MaxBrightness());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BrightnessStep(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().BrightnessStep());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DefaultBrightness(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().DefaultBrightness());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Brightness(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Brightness());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Brightness(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Brightness(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinContrast(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().MinContrast());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxContrast(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().MaxContrast());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContrastStep(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ContrastStep());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DefaultContrast(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().DefaultContrast());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Contrast(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Contrast());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Contrast(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Contrast(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Scanners::IImageScannerStatics> : produce_base<D, llm::OS::Devices::Scanners::IImageScannerStatics>
    {
        int32_t __stdcall FromIdAsync(void* deviceId, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Scanners::ImageScanner>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelector(void** selector) noexcept final try
        {
            clear_abi(selector);
            typename D::abi_guard guard(this->shim());
            *selector = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Scanners
{
    inline auto ImageScanner::FromIdAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<ImageScanner, IImageScannerStatics>([&](IImageScannerStatics const& f) { return f.FromIdAsync(deviceId); });
    }
    inline auto ImageScanner::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(IImageScannerStatics const&), ImageScanner, IImageScannerStatics>([](IImageScannerStatics const& f) { return f.GetDeviceSelector(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Scanners::IImageScanner> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Scanners::IImageScannerFeederConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Scanners::IImageScannerFormatConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Scanners::IImageScannerPreviewResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Scanners::IImageScannerScanResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Scanners::IImageScannerSourceConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Scanners::IImageScannerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Scanners::ImageScanner> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Scanners::ImageScannerAutoConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Scanners::ImageScannerFeederConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Scanners::ImageScannerFlatbedConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Scanners::ImageScannerPreviewResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Scanners::ImageScannerScanResult> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
