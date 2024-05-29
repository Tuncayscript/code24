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
#ifndef LLM_OS_Devices_PointOfService_2_H
#define LLM_OS_Devices_PointOfService_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Devices.PointOfService.1.h"
LLM_EXPORT namespace llm::OS::Devices::PointOfService
{
    struct SizeUInt32
    {
        uint32_t Width;
        uint32_t Height;
    };
    inline bool operator==(SizeUInt32 const& left, SizeUInt32 const& right) noexcept
    {
        return left.Width == right.Width && left.Height == right.Height;
    }
    inline bool operator!=(SizeUInt32 const& left, SizeUInt32 const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) BarcodeScanner : llm::OS::Devices::PointOfService::IBarcodeScanner,
        impl::require<BarcodeScanner, llm::OS::Devices::PointOfService::IBarcodeScanner2, llm::OS::Foundation::IClosable>
    {
        BarcodeScanner(std::nullptr_t) noexcept {}
        BarcodeScanner(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IBarcodeScanner(ptr, take_ownership_from_abi) {}
        static auto GetDefaultAsync();
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(llm::OS::Devices::PointOfService::PosConnectionTypes const& connectionTypes);
    };
    struct __declspec(empty_bases) BarcodeScannerCapabilities : llm::OS::Devices::PointOfService::IBarcodeScannerCapabilities,
        impl::require<BarcodeScannerCapabilities, llm::OS::Devices::PointOfService::IBarcodeScannerCapabilities1, llm::OS::Devices::PointOfService::IBarcodeScannerCapabilities2>
    {
        BarcodeScannerCapabilities(std::nullptr_t) noexcept {}
        BarcodeScannerCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IBarcodeScannerCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeScannerDataReceivedEventArgs : llm::OS::Devices::PointOfService::IBarcodeScannerDataReceivedEventArgs
    {
        BarcodeScannerDataReceivedEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerDataReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IBarcodeScannerDataReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeScannerErrorOccurredEventArgs : llm::OS::Devices::PointOfService::IBarcodeScannerErrorOccurredEventArgs
    {
        BarcodeScannerErrorOccurredEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerErrorOccurredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IBarcodeScannerErrorOccurredEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeScannerImagePreviewReceivedEventArgs : llm::OS::Devices::PointOfService::IBarcodeScannerImagePreviewReceivedEventArgs
    {
        BarcodeScannerImagePreviewReceivedEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerImagePreviewReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IBarcodeScannerImagePreviewReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeScannerReport : llm::OS::Devices::PointOfService::IBarcodeScannerReport
    {
        BarcodeScannerReport(std::nullptr_t) noexcept {}
        BarcodeScannerReport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IBarcodeScannerReport(ptr, take_ownership_from_abi) {}
        BarcodeScannerReport(uint32_t scanDataType, llm::OS::Storage::Streams::IBuffer const& scanData, llm::OS::Storage::Streams::IBuffer const& scanDataLabel);
    };
    struct __declspec(empty_bases) BarcodeScannerStatusUpdatedEventArgs : llm::OS::Devices::PointOfService::IBarcodeScannerStatusUpdatedEventArgs
    {
        BarcodeScannerStatusUpdatedEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerStatusUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IBarcodeScannerStatusUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct BarcodeSymbologies
    {
        BarcodeSymbologies() = delete;
        [[nodiscard]] static auto Unknown();
        [[nodiscard]] static auto Ean8();
        [[nodiscard]] static auto Ean8Add2();
        [[nodiscard]] static auto Ean8Add5();
        [[nodiscard]] static auto Eanv();
        [[nodiscard]] static auto EanvAdd2();
        [[nodiscard]] static auto EanvAdd5();
        [[nodiscard]] static auto Ean13();
        [[nodiscard]] static auto Ean13Add2();
        [[nodiscard]] static auto Ean13Add5();
        [[nodiscard]] static auto Isbn();
        [[nodiscard]] static auto IsbnAdd5();
        [[nodiscard]] static auto Ismn();
        [[nodiscard]] static auto IsmnAdd2();
        [[nodiscard]] static auto IsmnAdd5();
        [[nodiscard]] static auto Issn();
        [[nodiscard]] static auto IssnAdd2();
        [[nodiscard]] static auto IssnAdd5();
        [[nodiscard]] static auto Ean99();
        [[nodiscard]] static auto Ean99Add2();
        [[nodiscard]] static auto Ean99Add5();
        [[nodiscard]] static auto Upca();
        [[nodiscard]] static auto UpcaAdd2();
        [[nodiscard]] static auto UpcaAdd5();
        [[nodiscard]] static auto Upce();
        [[nodiscard]] static auto UpceAdd2();
        [[nodiscard]] static auto UpceAdd5();
        [[nodiscard]] static auto UpcCoupon();
        [[nodiscard]] static auto TfStd();
        [[nodiscard]] static auto TfDis();
        [[nodiscard]] static auto TfInt();
        [[nodiscard]] static auto TfInd();
        [[nodiscard]] static auto TfMat();
        [[nodiscard]] static auto TfIata();
        [[nodiscard]] static auto Gs1DatabarType1();
        [[nodiscard]] static auto Gs1DatabarType2();
        [[nodiscard]] static auto Gs1DatabarType3();
        [[nodiscard]] static auto Code39();
        [[nodiscard]] static auto Code39Ex();
        [[nodiscard]] static auto Trioptic39();
        [[nodiscard]] static auto Code32();
        [[nodiscard]] static auto Pzn();
        [[nodiscard]] static auto Code93();
        [[nodiscard]] static auto Code93Ex();
        [[nodiscard]] static auto Code128();
        [[nodiscard]] static auto Gs1128();
        [[nodiscard]] static auto Gs1128Coupon();
        [[nodiscard]] static auto UccEan128();
        [[nodiscard]] static auto Sisac();
        [[nodiscard]] static auto Isbt();
        [[nodiscard]] static auto Codabar();
        [[nodiscard]] static auto Code11();
        [[nodiscard]] static auto Msi();
        [[nodiscard]] static auto Plessey();
        [[nodiscard]] static auto Telepen();
        [[nodiscard]] static auto Code16k();
        [[nodiscard]] static auto CodablockA();
        [[nodiscard]] static auto CodablockF();
        [[nodiscard]] static auto Codablock128();
        [[nodiscard]] static auto Code49();
        [[nodiscard]] static auto Aztec();
        [[nodiscard]] static auto DataCode();
        [[nodiscard]] static auto DataMatrix();
        [[nodiscard]] static auto HanXin();
        [[nodiscard]] static auto Maxicode();
        [[nodiscard]] static auto MicroPdf417();
        [[nodiscard]] static auto MicroQr();
        [[nodiscard]] static auto Pdf417();
        [[nodiscard]] static auto Qr();
        [[nodiscard]] static auto MsTag();
        [[nodiscard]] static auto Ccab();
        [[nodiscard]] static auto Ccc();
        [[nodiscard]] static auto Tlc39();
        [[nodiscard]] static auto AusPost();
        [[nodiscard]] static auto CanPost();
        [[nodiscard]] static auto ChinaPost();
        [[nodiscard]] static auto DutchKix();
        [[nodiscard]] static auto InfoMail();
        [[nodiscard]] static auto ItalianPost25();
        [[nodiscard]] static auto ItalianPost39();
        [[nodiscard]] static auto JapanPost();
        [[nodiscard]] static auto KoreanPost();
        [[nodiscard]] static auto SwedenPost();
        [[nodiscard]] static auto UkPost();
        [[nodiscard]] static auto UsIntelligent();
        [[nodiscard]] static auto UsIntelligentPkg();
        [[nodiscard]] static auto UsPlanet();
        [[nodiscard]] static auto UsPostNet();
        [[nodiscard]] static auto Us4StateFics();
        [[nodiscard]] static auto OcrA();
        [[nodiscard]] static auto OcrB();
        [[nodiscard]] static auto Micr();
        [[nodiscard]] static auto ExtendedBase();
        static auto GetName(uint32_t scanDataType);
        [[nodiscard]] static auto Gs1DWCode();
    };
    struct __declspec(empty_bases) BarcodeSymbologyAttributes : llm::OS::Devices::PointOfService::IBarcodeSymbologyAttributes
    {
        BarcodeSymbologyAttributes(std::nullptr_t) noexcept {}
        BarcodeSymbologyAttributes(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IBarcodeSymbologyAttributes(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CashDrawer : llm::OS::Devices::PointOfService::ICashDrawer,
        impl::require<CashDrawer, llm::OS::Foundation::IClosable>
    {
        CashDrawer(std::nullptr_t) noexcept {}
        CashDrawer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ICashDrawer(ptr, take_ownership_from_abi) {}
        static auto GetDefaultAsync();
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(llm::OS::Devices::PointOfService::PosConnectionTypes const& connectionTypes);
    };
    struct __declspec(empty_bases) CashDrawerCapabilities : llm::OS::Devices::PointOfService::ICashDrawerCapabilities
    {
        CashDrawerCapabilities(std::nullptr_t) noexcept {}
        CashDrawerCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ICashDrawerCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CashDrawerCloseAlarm : llm::OS::Devices::PointOfService::ICashDrawerCloseAlarm
    {
        CashDrawerCloseAlarm(std::nullptr_t) noexcept {}
        CashDrawerCloseAlarm(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ICashDrawerCloseAlarm(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CashDrawerClosedEventArgs : llm::OS::Devices::PointOfService::ICashDrawerEventSourceEventArgs
    {
        CashDrawerClosedEventArgs(std::nullptr_t) noexcept {}
        CashDrawerClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ICashDrawerEventSourceEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CashDrawerEventSource : llm::OS::Devices::PointOfService::ICashDrawerEventSource
    {
        CashDrawerEventSource(std::nullptr_t) noexcept {}
        CashDrawerEventSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ICashDrawerEventSource(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CashDrawerOpenedEventArgs : llm::OS::Devices::PointOfService::ICashDrawerEventSourceEventArgs
    {
        CashDrawerOpenedEventArgs(std::nullptr_t) noexcept {}
        CashDrawerOpenedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ICashDrawerEventSourceEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CashDrawerStatus : llm::OS::Devices::PointOfService::ICashDrawerStatus
    {
        CashDrawerStatus(std::nullptr_t) noexcept {}
        CashDrawerStatus(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ICashDrawerStatus(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CashDrawerStatusUpdatedEventArgs : llm::OS::Devices::PointOfService::ICashDrawerStatusUpdatedEventArgs
    {
        CashDrawerStatusUpdatedEventArgs(std::nullptr_t) noexcept {}
        CashDrawerStatusUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ICashDrawerStatusUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ClaimedBarcodeScanner : llm::OS::Devices::PointOfService::IClaimedBarcodeScanner,
        impl::require<ClaimedBarcodeScanner, llm::OS::Devices::PointOfService::IClaimedBarcodeScanner1, llm::OS::Devices::PointOfService::IClaimedBarcodeScanner2, llm::OS::Devices::PointOfService::IClaimedBarcodeScanner3, llm::OS::Devices::PointOfService::IClaimedBarcodeScanner4, llm::OS::Foundation::IClosable>
    {
        ClaimedBarcodeScanner(std::nullptr_t) noexcept {}
        ClaimedBarcodeScanner(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IClaimedBarcodeScanner(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ClaimedBarcodeScannerClosedEventArgs : llm::OS::Devices::PointOfService::IClaimedBarcodeScannerClosedEventArgs
    {
        ClaimedBarcodeScannerClosedEventArgs(std::nullptr_t) noexcept {}
        ClaimedBarcodeScannerClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IClaimedBarcodeScannerClosedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ClaimedCashDrawer : llm::OS::Devices::PointOfService::IClaimedCashDrawer,
        impl::require<ClaimedCashDrawer, llm::OS::Devices::PointOfService::IClaimedCashDrawer2, llm::OS::Foundation::IClosable>
    {
        ClaimedCashDrawer(std::nullptr_t) noexcept {}
        ClaimedCashDrawer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IClaimedCashDrawer(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ClaimedCashDrawerClosedEventArgs : llm::OS::Devices::PointOfService::IClaimedCashDrawerClosedEventArgs
    {
        ClaimedCashDrawerClosedEventArgs(std::nullptr_t) noexcept {}
        ClaimedCashDrawerClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IClaimedCashDrawerClosedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ClaimedJournalPrinter : llm::OS::Devices::PointOfService::IClaimedJournalPrinter,
        impl::require<ClaimedJournalPrinter, llm::OS::Devices::PointOfService::ICommonClaimedPosPrinterStation>
    {
        ClaimedJournalPrinter(std::nullptr_t) noexcept {}
        ClaimedJournalPrinter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IClaimedJournalPrinter(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ClaimedLineDisplay : llm::OS::Devices::PointOfService::IClaimedLineDisplay,
        impl::require<ClaimedLineDisplay, llm::OS::Devices::PointOfService::IClaimedLineDisplay2, llm::OS::Devices::PointOfService::IClaimedLineDisplay3, llm::OS::Foundation::IClosable>
    {
        ClaimedLineDisplay(std::nullptr_t) noexcept {}
        ClaimedLineDisplay(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IClaimedLineDisplay(ptr, take_ownership_from_abi) {}
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(llm::OS::Devices::PointOfService::PosConnectionTypes const& connectionTypes);
    };
    struct __declspec(empty_bases) ClaimedLineDisplayClosedEventArgs : llm::OS::Devices::PointOfService::IClaimedLineDisplayClosedEventArgs
    {
        ClaimedLineDisplayClosedEventArgs(std::nullptr_t) noexcept {}
        ClaimedLineDisplayClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IClaimedLineDisplayClosedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ClaimedMagneticStripeReader : llm::OS::Devices::PointOfService::IClaimedMagneticStripeReader,
        impl::require<ClaimedMagneticStripeReader, llm::OS::Devices::PointOfService::IClaimedMagneticStripeReader2, llm::OS::Foundation::IClosable>
    {
        ClaimedMagneticStripeReader(std::nullptr_t) noexcept {}
        ClaimedMagneticStripeReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IClaimedMagneticStripeReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ClaimedMagneticStripeReaderClosedEventArgs : llm::OS::Devices::PointOfService::IClaimedMagneticStripeReaderClosedEventArgs
    {
        ClaimedMagneticStripeReaderClosedEventArgs(std::nullptr_t) noexcept {}
        ClaimedMagneticStripeReaderClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IClaimedMagneticStripeReaderClosedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ClaimedPosPrinter : llm::OS::Devices::PointOfService::IClaimedPosPrinter,
        impl::require<ClaimedPosPrinter, llm::OS::Devices::PointOfService::IClaimedPosPrinter2, llm::OS::Foundation::IClosable>
    {
        ClaimedPosPrinter(std::nullptr_t) noexcept {}
        ClaimedPosPrinter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IClaimedPosPrinter(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ClaimedPosPrinterClosedEventArgs : llm::OS::Devices::PointOfService::IClaimedPosPrinterClosedEventArgs
    {
        ClaimedPosPrinterClosedEventArgs(std::nullptr_t) noexcept {}
        ClaimedPosPrinterClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IClaimedPosPrinterClosedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ClaimedReceiptPrinter : llm::OS::Devices::PointOfService::IClaimedReceiptPrinter,
        impl::require<ClaimedReceiptPrinter, llm::OS::Devices::PointOfService::ICommonClaimedPosPrinterStation>
    {
        ClaimedReceiptPrinter(std::nullptr_t) noexcept {}
        ClaimedReceiptPrinter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IClaimedReceiptPrinter(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ClaimedSlipPrinter : llm::OS::Devices::PointOfService::IClaimedSlipPrinter,
        impl::require<ClaimedSlipPrinter, llm::OS::Devices::PointOfService::ICommonClaimedPosPrinterStation>
    {
        ClaimedSlipPrinter(std::nullptr_t) noexcept {}
        ClaimedSlipPrinter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IClaimedSlipPrinter(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) JournalPrintJob : llm::OS::Devices::PointOfService::IPosPrinterJob,
        impl::require<JournalPrintJob, llm::OS::Devices::PointOfService::IJournalPrintJob>
    {
        JournalPrintJob(std::nullptr_t) noexcept {}
        JournalPrintJob(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IPosPrinterJob(ptr, take_ownership_from_abi) {}
        using impl::consume_t<JournalPrintJob, llm::OS::Devices::PointOfService::IJournalPrintJob>::Print;
        using llm::OS::Devices::PointOfService::IPosPrinterJob::Print;
    };
    struct __declspec(empty_bases) JournalPrinterCapabilities : llm::OS::Devices::PointOfService::IJournalPrinterCapabilities,
        impl::require<JournalPrinterCapabilities, llm::OS::Devices::PointOfService::IJournalPrinterCapabilities2, llm::OS::Devices::PointOfService::ICommonPosPrintStationCapabilities>
    {
        JournalPrinterCapabilities(std::nullptr_t) noexcept {}
        JournalPrinterCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IJournalPrinterCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LineDisplay : llm::OS::Devices::PointOfService::ILineDisplay,
        impl::require<LineDisplay, llm::OS::Devices::PointOfService::ILineDisplay2, llm::OS::Foundation::IClosable>
    {
        LineDisplay(std::nullptr_t) noexcept {}
        LineDisplay(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ILineDisplay(ptr, take_ownership_from_abi) {}
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDefaultAsync();
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(llm::OS::Devices::PointOfService::PosConnectionTypes const& connectionTypes);
        [[nodiscard]] static auto StatisticsCategorySelector();
    };
    struct __declspec(empty_bases) LineDisplayAttributes : llm::OS::Devices::PointOfService::ILineDisplayAttributes
    {
        LineDisplayAttributes(std::nullptr_t) noexcept {}
        LineDisplayAttributes(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ILineDisplayAttributes(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LineDisplayCapabilities : llm::OS::Devices::PointOfService::ILineDisplayCapabilities
    {
        LineDisplayCapabilities(std::nullptr_t) noexcept {}
        LineDisplayCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ILineDisplayCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LineDisplayCursor : llm::OS::Devices::PointOfService::ILineDisplayCursor
    {
        LineDisplayCursor(std::nullptr_t) noexcept {}
        LineDisplayCursor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ILineDisplayCursor(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LineDisplayCursorAttributes : llm::OS::Devices::PointOfService::ILineDisplayCursorAttributes
    {
        LineDisplayCursorAttributes(std::nullptr_t) noexcept {}
        LineDisplayCursorAttributes(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ILineDisplayCursorAttributes(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LineDisplayCustomGlyphs : llm::OS::Devices::PointOfService::ILineDisplayCustomGlyphs
    {
        LineDisplayCustomGlyphs(std::nullptr_t) noexcept {}
        LineDisplayCustomGlyphs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ILineDisplayCustomGlyphs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LineDisplayMarquee : llm::OS::Devices::PointOfService::ILineDisplayMarquee
    {
        LineDisplayMarquee(std::nullptr_t) noexcept {}
        LineDisplayMarquee(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ILineDisplayMarquee(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LineDisplayStatisticsCategorySelector : llm::OS::Devices::PointOfService::ILineDisplayStatisticsCategorySelector
    {
        LineDisplayStatisticsCategorySelector(std::nullptr_t) noexcept {}
        LineDisplayStatisticsCategorySelector(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ILineDisplayStatisticsCategorySelector(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LineDisplayStatusUpdatedEventArgs : llm::OS::Devices::PointOfService::ILineDisplayStatusUpdatedEventArgs
    {
        LineDisplayStatusUpdatedEventArgs(std::nullptr_t) noexcept {}
        LineDisplayStatusUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ILineDisplayStatusUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LineDisplayStoredBitmap : llm::OS::Devices::PointOfService::ILineDisplayStoredBitmap
    {
        LineDisplayStoredBitmap(std::nullptr_t) noexcept {}
        LineDisplayStoredBitmap(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ILineDisplayStoredBitmap(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LineDisplayWindow : llm::OS::Devices::PointOfService::ILineDisplayWindow,
        impl::require<LineDisplayWindow, llm::OS::Devices::PointOfService::ILineDisplayWindow2, llm::OS::Foundation::IClosable>
    {
        LineDisplayWindow(std::nullptr_t) noexcept {}
        LineDisplayWindow(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ILineDisplayWindow(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MagneticStripeReader : llm::OS::Devices::PointOfService::IMagneticStripeReader,
        impl::require<MagneticStripeReader, llm::OS::Foundation::IClosable>
    {
        MagneticStripeReader(std::nullptr_t) noexcept {}
        MagneticStripeReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IMagneticStripeReader(ptr, take_ownership_from_abi) {}
        static auto GetDefaultAsync();
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(llm::OS::Devices::PointOfService::PosConnectionTypes const& connectionTypes);
    };
    struct __declspec(empty_bases) MagneticStripeReaderAamvaCardDataReceivedEventArgs : llm::OS::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs
    {
        MagneticStripeReaderAamvaCardDataReceivedEventArgs(std::nullptr_t) noexcept {}
        MagneticStripeReaderAamvaCardDataReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MagneticStripeReaderBankCardDataReceivedEventArgs : llm::OS::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs
    {
        MagneticStripeReaderBankCardDataReceivedEventArgs(std::nullptr_t) noexcept {}
        MagneticStripeReaderBankCardDataReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MagneticStripeReaderCapabilities : llm::OS::Devices::PointOfService::IMagneticStripeReaderCapabilities
    {
        MagneticStripeReaderCapabilities(std::nullptr_t) noexcept {}
        MagneticStripeReaderCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IMagneticStripeReaderCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct MagneticStripeReaderCardTypes
    {
        MagneticStripeReaderCardTypes() = delete;
        [[nodiscard]] static auto Unknown();
        [[nodiscard]] static auto Bank();
        [[nodiscard]] static auto Aamva();
        [[nodiscard]] static auto ExtendedBase();
    };
    struct MagneticStripeReaderEncryptionAlgorithms
    {
        MagneticStripeReaderEncryptionAlgorithms() = delete;
        [[nodiscard]] static auto None();
        [[nodiscard]] static auto TripleDesDukpt();
        [[nodiscard]] static auto ExtendedBase();
    };
    struct __declspec(empty_bases) MagneticStripeReaderErrorOccurredEventArgs : llm::OS::Devices::PointOfService::IMagneticStripeReaderErrorOccurredEventArgs
    {
        MagneticStripeReaderErrorOccurredEventArgs(std::nullptr_t) noexcept {}
        MagneticStripeReaderErrorOccurredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IMagneticStripeReaderErrorOccurredEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MagneticStripeReaderReport : llm::OS::Devices::PointOfService::IMagneticStripeReaderReport
    {
        MagneticStripeReaderReport(std::nullptr_t) noexcept {}
        MagneticStripeReaderReport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IMagneticStripeReaderReport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MagneticStripeReaderStatusUpdatedEventArgs : llm::OS::Devices::PointOfService::IMagneticStripeReaderStatusUpdatedEventArgs
    {
        MagneticStripeReaderStatusUpdatedEventArgs(std::nullptr_t) noexcept {}
        MagneticStripeReaderStatusUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IMagneticStripeReaderStatusUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MagneticStripeReaderTrackData : llm::OS::Devices::PointOfService::IMagneticStripeReaderTrackData
    {
        MagneticStripeReaderTrackData(std::nullptr_t) noexcept {}
        MagneticStripeReaderTrackData(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IMagneticStripeReaderTrackData(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs : llm::OS::Devices::PointOfService::IMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs
    {
        MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs(std::nullptr_t) noexcept {}
        MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PosPrinter : llm::OS::Devices::PointOfService::IPosPrinter,
        impl::require<PosPrinter, llm::OS::Devices::PointOfService::IPosPrinter2, llm::OS::Foundation::IClosable>
    {
        PosPrinter(std::nullptr_t) noexcept {}
        PosPrinter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IPosPrinter(ptr, take_ownership_from_abi) {}
        static auto GetDefaultAsync();
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(llm::OS::Devices::PointOfService::PosConnectionTypes const& connectionTypes);
    };
    struct __declspec(empty_bases) PosPrinterCapabilities : llm::OS::Devices::PointOfService::IPosPrinterCapabilities
    {
        PosPrinterCapabilities(std::nullptr_t) noexcept {}
        PosPrinterCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IPosPrinterCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct PosPrinterCharacterSetIds
    {
        PosPrinterCharacterSetIds() = delete;
        [[nodiscard]] static auto Utf16LE();
        [[nodiscard]] static auto Ascii();
        [[nodiscard]] static auto Ansi();
    };
    struct __declspec(empty_bases) PosPrinterFontProperty : llm::OS::Devices::PointOfService::IPosPrinterFontProperty
    {
        PosPrinterFontProperty(std::nullptr_t) noexcept {}
        PosPrinterFontProperty(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IPosPrinterFontProperty(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PosPrinterPrintOptions : llm::OS::Devices::PointOfService::IPosPrinterPrintOptions
    {
        PosPrinterPrintOptions(std::nullptr_t) noexcept {}
        PosPrinterPrintOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IPosPrinterPrintOptions(ptr, take_ownership_from_abi) {}
        PosPrinterPrintOptions();
    };
    struct __declspec(empty_bases) PosPrinterReleaseDeviceRequestedEventArgs : llm::OS::Devices::PointOfService::IPosPrinterReleaseDeviceRequestedEventArgs
    {
        PosPrinterReleaseDeviceRequestedEventArgs(std::nullptr_t) noexcept {}
        PosPrinterReleaseDeviceRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IPosPrinterReleaseDeviceRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PosPrinterStatus : llm::OS::Devices::PointOfService::IPosPrinterStatus
    {
        PosPrinterStatus(std::nullptr_t) noexcept {}
        PosPrinterStatus(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IPosPrinterStatus(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PosPrinterStatusUpdatedEventArgs : llm::OS::Devices::PointOfService::IPosPrinterStatusUpdatedEventArgs
    {
        PosPrinterStatusUpdatedEventArgs(std::nullptr_t) noexcept {}
        PosPrinterStatusUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IPosPrinterStatusUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ReceiptPrintJob : llm::OS::Devices::PointOfService::IReceiptPrintJob,
        impl::require<ReceiptPrintJob, llm::OS::Devices::PointOfService::IReceiptPrintJob2, llm::OS::Devices::PointOfService::IPosPrinterJob, llm::OS::Devices::PointOfService::IReceiptOrSlipJob>
    {
        ReceiptPrintJob(std::nullptr_t) noexcept {}
        ReceiptPrintJob(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IReceiptPrintJob(ptr, take_ownership_from_abi) {}
        using impl::consume_t<ReceiptPrintJob, llm::OS::Devices::PointOfService::IPosPrinterJob>::Print;
        using impl::consume_t<ReceiptPrintJob, llm::OS::Devices::PointOfService::IReceiptPrintJob2>::Print;
    };
    struct __declspec(empty_bases) ReceiptPrinterCapabilities : llm::OS::Devices::PointOfService::IReceiptPrinterCapabilities,
        impl::require<ReceiptPrinterCapabilities, llm::OS::Devices::PointOfService::IReceiptPrinterCapabilities2, llm::OS::Devices::PointOfService::ICommonPosPrintStationCapabilities, llm::OS::Devices::PointOfService::ICommonReceiptSlipCapabilities>
    {
        ReceiptPrinterCapabilities(std::nullptr_t) noexcept {}
        ReceiptPrinterCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IReceiptPrinterCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SlipPrintJob : llm::OS::Devices::PointOfService::IReceiptOrSlipJob,
        impl::require<SlipPrintJob, llm::OS::Devices::PointOfService::ISlipPrintJob>
    {
        SlipPrintJob(std::nullptr_t) noexcept {}
        SlipPrintJob(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IReceiptOrSlipJob(ptr, take_ownership_from_abi) {}
        using llm::OS::Devices::PointOfService::IReceiptOrSlipJob::Print;
        using impl::consume_t<SlipPrintJob, llm::OS::Devices::PointOfService::ISlipPrintJob>::Print;
    };
    struct __declspec(empty_bases) SlipPrinterCapabilities : llm::OS::Devices::PointOfService::ISlipPrinterCapabilities,
        impl::require<SlipPrinterCapabilities, llm::OS::Devices::PointOfService::ISlipPrinterCapabilities2, llm::OS::Devices::PointOfService::ICommonPosPrintStationCapabilities, llm::OS::Devices::PointOfService::ICommonReceiptSlipCapabilities>
    {
        SlipPrinterCapabilities(std::nullptr_t) noexcept {}
        SlipPrinterCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::ISlipPrinterCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UnifiedPosErrorData : llm::OS::Devices::PointOfService::IUnifiedPosErrorData
    {
        UnifiedPosErrorData(std::nullptr_t) noexcept {}
        UnifiedPosErrorData(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::IUnifiedPosErrorData(ptr, take_ownership_from_abi) {}
        UnifiedPosErrorData(param::hstring const& message, llm::OS::Devices::PointOfService::UnifiedPosErrorSeverity const& severity, llm::OS::Devices::PointOfService::UnifiedPosErrorReason const& reason, uint32_t extendedReason);
    };
}
#endif
