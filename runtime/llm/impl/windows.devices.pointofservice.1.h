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
#ifndef LLM_OS_Devices_PointOfService_1_H
#define LLM_OS_Devices_PointOfService_1_H
#include "llm/impl/Windows.Devices.PointOfService.0.h"
LLM_EXPORT namespace llm::OS::Devices::PointOfService
{
    struct __declspec(empty_bases) IBarcodeScanner :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScanner>
    {
        IBarcodeScanner(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScanner(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScanner2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScanner2>
    {
        IBarcodeScanner2(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScanner2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerCapabilities :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerCapabilities>
    {
        IBarcodeScannerCapabilities(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerCapabilities1 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerCapabilities1>
    {
        IBarcodeScannerCapabilities1(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerCapabilities1(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerCapabilities2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerCapabilities2>
    {
        IBarcodeScannerCapabilities2(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerCapabilities2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerDataReceivedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerDataReceivedEventArgs>
    {
        IBarcodeScannerDataReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerDataReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerErrorOccurredEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerErrorOccurredEventArgs>
    {
        IBarcodeScannerErrorOccurredEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerErrorOccurredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerImagePreviewReceivedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerImagePreviewReceivedEventArgs>
    {
        IBarcodeScannerImagePreviewReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerImagePreviewReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerReport :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerReport>
    {
        IBarcodeScannerReport(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerReport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerReportFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerReportFactory>
    {
        IBarcodeScannerReportFactory(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerReportFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerStatics>
    {
        IBarcodeScannerStatics(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerStatics2>
    {
        IBarcodeScannerStatics2(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerStatusUpdatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerStatusUpdatedEventArgs>
    {
        IBarcodeScannerStatusUpdatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerStatusUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeSymbologiesStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeSymbologiesStatics>
    {
        IBarcodeSymbologiesStatics(std::nullptr_t = nullptr) noexcept {}
        IBarcodeSymbologiesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeSymbologiesStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeSymbologiesStatics2>
    {
        IBarcodeSymbologiesStatics2(std::nullptr_t = nullptr) noexcept {}
        IBarcodeSymbologiesStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeSymbologyAttributes :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeSymbologyAttributes>
    {
        IBarcodeSymbologyAttributes(std::nullptr_t = nullptr) noexcept {}
        IBarcodeSymbologyAttributes(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICashDrawer :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICashDrawer>
    {
        ICashDrawer(std::nullptr_t = nullptr) noexcept {}
        ICashDrawer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICashDrawerCapabilities :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICashDrawerCapabilities>
    {
        ICashDrawerCapabilities(std::nullptr_t = nullptr) noexcept {}
        ICashDrawerCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICashDrawerCloseAlarm :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICashDrawerCloseAlarm>
    {
        ICashDrawerCloseAlarm(std::nullptr_t = nullptr) noexcept {}
        ICashDrawerCloseAlarm(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICashDrawerEventSource :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICashDrawerEventSource>
    {
        ICashDrawerEventSource(std::nullptr_t = nullptr) noexcept {}
        ICashDrawerEventSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICashDrawerEventSourceEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICashDrawerEventSourceEventArgs>
    {
        ICashDrawerEventSourceEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICashDrawerEventSourceEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICashDrawerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICashDrawerStatics>
    {
        ICashDrawerStatics(std::nullptr_t = nullptr) noexcept {}
        ICashDrawerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICashDrawerStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICashDrawerStatics2>
    {
        ICashDrawerStatics2(std::nullptr_t = nullptr) noexcept {}
        ICashDrawerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICashDrawerStatus :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICashDrawerStatus>
    {
        ICashDrawerStatus(std::nullptr_t = nullptr) noexcept {}
        ICashDrawerStatus(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICashDrawerStatusUpdatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICashDrawerStatusUpdatedEventArgs>
    {
        ICashDrawerStatusUpdatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICashDrawerStatusUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedBarcodeScanner :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedBarcodeScanner>
    {
        IClaimedBarcodeScanner(std::nullptr_t = nullptr) noexcept {}
        IClaimedBarcodeScanner(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedBarcodeScanner1 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedBarcodeScanner1>
    {
        IClaimedBarcodeScanner1(std::nullptr_t = nullptr) noexcept {}
        IClaimedBarcodeScanner1(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedBarcodeScanner2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedBarcodeScanner2>
    {
        IClaimedBarcodeScanner2(std::nullptr_t = nullptr) noexcept {}
        IClaimedBarcodeScanner2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedBarcodeScanner3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedBarcodeScanner3>
    {
        IClaimedBarcodeScanner3(std::nullptr_t = nullptr) noexcept {}
        IClaimedBarcodeScanner3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedBarcodeScanner4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedBarcodeScanner4>
    {
        IClaimedBarcodeScanner4(std::nullptr_t = nullptr) noexcept {}
        IClaimedBarcodeScanner4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedBarcodeScannerClosedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedBarcodeScannerClosedEventArgs>
    {
        IClaimedBarcodeScannerClosedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IClaimedBarcodeScannerClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedCashDrawer :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedCashDrawer>
    {
        IClaimedCashDrawer(std::nullptr_t = nullptr) noexcept {}
        IClaimedCashDrawer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedCashDrawer2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedCashDrawer2>
    {
        IClaimedCashDrawer2(std::nullptr_t = nullptr) noexcept {}
        IClaimedCashDrawer2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedCashDrawerClosedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedCashDrawerClosedEventArgs>
    {
        IClaimedCashDrawerClosedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IClaimedCashDrawerClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedJournalPrinter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedJournalPrinter>
    {
        IClaimedJournalPrinter(std::nullptr_t = nullptr) noexcept {}
        IClaimedJournalPrinter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedLineDisplay :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedLineDisplay>
    {
        IClaimedLineDisplay(std::nullptr_t = nullptr) noexcept {}
        IClaimedLineDisplay(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedLineDisplay2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedLineDisplay2>
    {
        IClaimedLineDisplay2(std::nullptr_t = nullptr) noexcept {}
        IClaimedLineDisplay2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedLineDisplay3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedLineDisplay3>
    {
        IClaimedLineDisplay3(std::nullptr_t = nullptr) noexcept {}
        IClaimedLineDisplay3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedLineDisplayClosedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedLineDisplayClosedEventArgs>
    {
        IClaimedLineDisplayClosedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IClaimedLineDisplayClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedLineDisplayStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedLineDisplayStatics>
    {
        IClaimedLineDisplayStatics(std::nullptr_t = nullptr) noexcept {}
        IClaimedLineDisplayStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedMagneticStripeReader :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedMagneticStripeReader>
    {
        IClaimedMagneticStripeReader(std::nullptr_t = nullptr) noexcept {}
        IClaimedMagneticStripeReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedMagneticStripeReader2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedMagneticStripeReader2>
    {
        IClaimedMagneticStripeReader2(std::nullptr_t = nullptr) noexcept {}
        IClaimedMagneticStripeReader2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedMagneticStripeReaderClosedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedMagneticStripeReaderClosedEventArgs>
    {
        IClaimedMagneticStripeReaderClosedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IClaimedMagneticStripeReaderClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedPosPrinter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedPosPrinter>
    {
        IClaimedPosPrinter(std::nullptr_t = nullptr) noexcept {}
        IClaimedPosPrinter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedPosPrinter2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedPosPrinter2>
    {
        IClaimedPosPrinter2(std::nullptr_t = nullptr) noexcept {}
        IClaimedPosPrinter2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedPosPrinterClosedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedPosPrinterClosedEventArgs>
    {
        IClaimedPosPrinterClosedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IClaimedPosPrinterClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedReceiptPrinter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedReceiptPrinter>
    {
        IClaimedReceiptPrinter(std::nullptr_t = nullptr) noexcept {}
        IClaimedReceiptPrinter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClaimedSlipPrinter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClaimedSlipPrinter>
    {
        IClaimedSlipPrinter(std::nullptr_t = nullptr) noexcept {}
        IClaimedSlipPrinter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICommonClaimedPosPrinterStation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICommonClaimedPosPrinterStation>
    {
        ICommonClaimedPosPrinterStation(std::nullptr_t = nullptr) noexcept {}
        ICommonClaimedPosPrinterStation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICommonPosPrintStationCapabilities :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICommonPosPrintStationCapabilities>
    {
        ICommonPosPrintStationCapabilities(std::nullptr_t = nullptr) noexcept {}
        ICommonPosPrintStationCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICommonReceiptSlipCapabilities :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICommonReceiptSlipCapabilities>,
        impl::require<llm::OS::Devices::PointOfService::ICommonReceiptSlipCapabilities, llm::OS::Devices::PointOfService::ICommonPosPrintStationCapabilities>
    {
        ICommonReceiptSlipCapabilities(std::nullptr_t = nullptr) noexcept {}
        ICommonReceiptSlipCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IJournalPrintJob :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IJournalPrintJob>
    {
        IJournalPrintJob(std::nullptr_t = nullptr) noexcept {}
        IJournalPrintJob(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IJournalPrinterCapabilities :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IJournalPrinterCapabilities>
    {
        IJournalPrinterCapabilities(std::nullptr_t = nullptr) noexcept {}
        IJournalPrinterCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IJournalPrinterCapabilities2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IJournalPrinterCapabilities2>
    {
        IJournalPrinterCapabilities2(std::nullptr_t = nullptr) noexcept {}
        IJournalPrinterCapabilities2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILineDisplay :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILineDisplay>
    {
        ILineDisplay(std::nullptr_t = nullptr) noexcept {}
        ILineDisplay(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILineDisplay2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILineDisplay2>
    {
        ILineDisplay2(std::nullptr_t = nullptr) noexcept {}
        ILineDisplay2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILineDisplayAttributes :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILineDisplayAttributes>
    {
        ILineDisplayAttributes(std::nullptr_t = nullptr) noexcept {}
        ILineDisplayAttributes(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILineDisplayCapabilities :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILineDisplayCapabilities>
    {
        ILineDisplayCapabilities(std::nullptr_t = nullptr) noexcept {}
        ILineDisplayCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILineDisplayCursor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILineDisplayCursor>
    {
        ILineDisplayCursor(std::nullptr_t = nullptr) noexcept {}
        ILineDisplayCursor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILineDisplayCursorAttributes :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILineDisplayCursorAttributes>
    {
        ILineDisplayCursorAttributes(std::nullptr_t = nullptr) noexcept {}
        ILineDisplayCursorAttributes(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILineDisplayCustomGlyphs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILineDisplayCustomGlyphs>
    {
        ILineDisplayCustomGlyphs(std::nullptr_t = nullptr) noexcept {}
        ILineDisplayCustomGlyphs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILineDisplayMarquee :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILineDisplayMarquee>
    {
        ILineDisplayMarquee(std::nullptr_t = nullptr) noexcept {}
        ILineDisplayMarquee(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILineDisplayStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILineDisplayStatics>
    {
        ILineDisplayStatics(std::nullptr_t = nullptr) noexcept {}
        ILineDisplayStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILineDisplayStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILineDisplayStatics2>
    {
        ILineDisplayStatics2(std::nullptr_t = nullptr) noexcept {}
        ILineDisplayStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILineDisplayStatisticsCategorySelector :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILineDisplayStatisticsCategorySelector>
    {
        ILineDisplayStatisticsCategorySelector(std::nullptr_t = nullptr) noexcept {}
        ILineDisplayStatisticsCategorySelector(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILineDisplayStatusUpdatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILineDisplayStatusUpdatedEventArgs>
    {
        ILineDisplayStatusUpdatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ILineDisplayStatusUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILineDisplayStoredBitmap :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILineDisplayStoredBitmap>
    {
        ILineDisplayStoredBitmap(std::nullptr_t = nullptr) noexcept {}
        ILineDisplayStoredBitmap(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILineDisplayWindow :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILineDisplayWindow>
    {
        ILineDisplayWindow(std::nullptr_t = nullptr) noexcept {}
        ILineDisplayWindow(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILineDisplayWindow2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILineDisplayWindow2>
    {
        ILineDisplayWindow2(std::nullptr_t = nullptr) noexcept {}
        ILineDisplayWindow2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMagneticStripeReader :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMagneticStripeReader>
    {
        IMagneticStripeReader(std::nullptr_t = nullptr) noexcept {}
        IMagneticStripeReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMagneticStripeReaderAamvaCardDataReceivedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMagneticStripeReaderAamvaCardDataReceivedEventArgs>
    {
        IMagneticStripeReaderAamvaCardDataReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMagneticStripeReaderAamvaCardDataReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMagneticStripeReaderBankCardDataReceivedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMagneticStripeReaderBankCardDataReceivedEventArgs>
    {
        IMagneticStripeReaderBankCardDataReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMagneticStripeReaderBankCardDataReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMagneticStripeReaderCapabilities :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMagneticStripeReaderCapabilities>
    {
        IMagneticStripeReaderCapabilities(std::nullptr_t = nullptr) noexcept {}
        IMagneticStripeReaderCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMagneticStripeReaderCardTypesStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMagneticStripeReaderCardTypesStatics>
    {
        IMagneticStripeReaderCardTypesStatics(std::nullptr_t = nullptr) noexcept {}
        IMagneticStripeReaderCardTypesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMagneticStripeReaderEncryptionAlgorithmsStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMagneticStripeReaderEncryptionAlgorithmsStatics>
    {
        IMagneticStripeReaderEncryptionAlgorithmsStatics(std::nullptr_t = nullptr) noexcept {}
        IMagneticStripeReaderEncryptionAlgorithmsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMagneticStripeReaderErrorOccurredEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMagneticStripeReaderErrorOccurredEventArgs>
    {
        IMagneticStripeReaderErrorOccurredEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMagneticStripeReaderErrorOccurredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMagneticStripeReaderReport :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMagneticStripeReaderReport>
    {
        IMagneticStripeReaderReport(std::nullptr_t = nullptr) noexcept {}
        IMagneticStripeReaderReport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMagneticStripeReaderStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMagneticStripeReaderStatics>
    {
        IMagneticStripeReaderStatics(std::nullptr_t = nullptr) noexcept {}
        IMagneticStripeReaderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMagneticStripeReaderStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMagneticStripeReaderStatics2>
    {
        IMagneticStripeReaderStatics2(std::nullptr_t = nullptr) noexcept {}
        IMagneticStripeReaderStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMagneticStripeReaderStatusUpdatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMagneticStripeReaderStatusUpdatedEventArgs>
    {
        IMagneticStripeReaderStatusUpdatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMagneticStripeReaderStatusUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMagneticStripeReaderTrackData :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMagneticStripeReaderTrackData>
    {
        IMagneticStripeReaderTrackData(std::nullptr_t = nullptr) noexcept {}
        IMagneticStripeReaderTrackData(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs>
    {
        IMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPosPrinter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPosPrinter>
    {
        IPosPrinter(std::nullptr_t = nullptr) noexcept {}
        IPosPrinter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPosPrinter2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPosPrinter2>
    {
        IPosPrinter2(std::nullptr_t = nullptr) noexcept {}
        IPosPrinter2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPosPrinterCapabilities :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPosPrinterCapabilities>
    {
        IPosPrinterCapabilities(std::nullptr_t = nullptr) noexcept {}
        IPosPrinterCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPosPrinterCharacterSetIdsStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPosPrinterCharacterSetIdsStatics>
    {
        IPosPrinterCharacterSetIdsStatics(std::nullptr_t = nullptr) noexcept {}
        IPosPrinterCharacterSetIdsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPosPrinterFontProperty :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPosPrinterFontProperty>
    {
        IPosPrinterFontProperty(std::nullptr_t = nullptr) noexcept {}
        IPosPrinterFontProperty(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPosPrinterJob :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPosPrinterJob>
    {
        IPosPrinterJob(std::nullptr_t = nullptr) noexcept {}
        IPosPrinterJob(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPosPrinterPrintOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPosPrinterPrintOptions>
    {
        IPosPrinterPrintOptions(std::nullptr_t = nullptr) noexcept {}
        IPosPrinterPrintOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPosPrinterReleaseDeviceRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPosPrinterReleaseDeviceRequestedEventArgs>
    {
        IPosPrinterReleaseDeviceRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPosPrinterReleaseDeviceRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPosPrinterStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPosPrinterStatics>
    {
        IPosPrinterStatics(std::nullptr_t = nullptr) noexcept {}
        IPosPrinterStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPosPrinterStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPosPrinterStatics2>
    {
        IPosPrinterStatics2(std::nullptr_t = nullptr) noexcept {}
        IPosPrinterStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPosPrinterStatus :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPosPrinterStatus>
    {
        IPosPrinterStatus(std::nullptr_t = nullptr) noexcept {}
        IPosPrinterStatus(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPosPrinterStatusUpdatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPosPrinterStatusUpdatedEventArgs>
    {
        IPosPrinterStatusUpdatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPosPrinterStatusUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IReceiptOrSlipJob :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IReceiptOrSlipJob>,
        impl::require<llm::OS::Devices::PointOfService::IReceiptOrSlipJob, llm::OS::Devices::PointOfService::IPosPrinterJob>
    {
        IReceiptOrSlipJob(std::nullptr_t = nullptr) noexcept {}
        IReceiptOrSlipJob(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IReceiptPrintJob :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IReceiptPrintJob>
    {
        IReceiptPrintJob(std::nullptr_t = nullptr) noexcept {}
        IReceiptPrintJob(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IReceiptPrintJob2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IReceiptPrintJob2>
    {
        IReceiptPrintJob2(std::nullptr_t = nullptr) noexcept {}
        IReceiptPrintJob2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IReceiptPrinterCapabilities :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IReceiptPrinterCapabilities>
    {
        IReceiptPrinterCapabilities(std::nullptr_t = nullptr) noexcept {}
        IReceiptPrinterCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IReceiptPrinterCapabilities2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IReceiptPrinterCapabilities2>
    {
        IReceiptPrinterCapabilities2(std::nullptr_t = nullptr) noexcept {}
        IReceiptPrinterCapabilities2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISlipPrintJob :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISlipPrintJob>
    {
        ISlipPrintJob(std::nullptr_t = nullptr) noexcept {}
        ISlipPrintJob(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISlipPrinterCapabilities :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISlipPrinterCapabilities>
    {
        ISlipPrinterCapabilities(std::nullptr_t = nullptr) noexcept {}
        ISlipPrinterCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISlipPrinterCapabilities2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISlipPrinterCapabilities2>
    {
        ISlipPrinterCapabilities2(std::nullptr_t = nullptr) noexcept {}
        ISlipPrinterCapabilities2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUnifiedPosErrorData :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUnifiedPosErrorData>
    {
        IUnifiedPosErrorData(std::nullptr_t = nullptr) noexcept {}
        IUnifiedPosErrorData(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUnifiedPosErrorDataFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUnifiedPosErrorDataFactory>
    {
        IUnifiedPosErrorDataFactory(std::nullptr_t = nullptr) noexcept {}
        IUnifiedPosErrorDataFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
