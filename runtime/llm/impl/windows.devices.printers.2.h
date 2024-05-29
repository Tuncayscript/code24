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
#ifndef LLM_OS_Devices_Printers_2_H
#define LLM_OS_Devices_Printers_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Devices.Printers.1.h"
LLM_EXPORT namespace llm::OS::Devices::Printers
{
    struct __declspec(empty_bases) IppAttributeError : llm::OS::Devices::Printers::IIppAttributeError
    {
        IppAttributeError(std::nullptr_t) noexcept {}
        IppAttributeError(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::IIppAttributeError(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IppAttributeValue : llm::OS::Devices::Printers::IIppAttributeValue
    {
        IppAttributeValue(std::nullptr_t) noexcept {}
        IppAttributeValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::IIppAttributeValue(ptr, take_ownership_from_abi) {}
        static auto CreateUnsupported();
        static auto CreateUnknown();
        static auto CreateNoValue();
        static auto CreateInteger(int32_t value);
        static auto CreateIntegerArray(param::iterable<int32_t> const& values);
        static auto CreateBoolean(bool value);
        static auto CreateBooleanArray(param::iterable<bool> const& values);
        static auto CreateEnum(int32_t value);
        static auto CreateEnumArray(param::iterable<int32_t> const& values);
        static auto CreateOctetString(llm::OS::Storage::Streams::IBuffer const& value);
        static auto CreateOctetStringArray(param::iterable<llm::OS::Storage::Streams::IBuffer> const& values);
        static auto CreateDateTime(llm::OS::Foundation::DateTime const& value);
        static auto CreateDateTimeArray(param::iterable<llm::OS::Foundation::DateTime> const& values);
        static auto CreateResolution(llm::OS::Devices::Printers::IppResolution const& value);
        static auto CreateResolutionArray(param::iterable<llm::OS::Devices::Printers::IppResolution> const& values);
        static auto CreateRangeOfInteger(llm::OS::Devices::Printers::IppIntegerRange const& value);
        static auto CreateRangeOfIntegerArray(param::iterable<llm::OS::Devices::Printers::IppIntegerRange> const& values);
        static auto CreateCollection(param::iterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Devices::Printers::IppAttributeValue>> const& memberAttributes);
        static auto CreateCollectionArray(param::iterable<llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Devices::Printers::IppAttributeValue>>> const& memberAttributesArray);
        static auto CreateTextWithLanguage(llm::OS::Devices::Printers::IppTextWithLanguage const& value);
        static auto CreateTextWithLanguageArray(param::iterable<llm::OS::Devices::Printers::IppTextWithLanguage> const& values);
        static auto CreateNameWithLanguage(llm::OS::Devices::Printers::IppTextWithLanguage const& value);
        static auto CreateNameWithLanguageArray(param::iterable<llm::OS::Devices::Printers::IppTextWithLanguage> const& values);
        static auto CreateTextWithoutLanguage(param::hstring const& value);
        static auto CreateTextWithoutLanguageArray(param::iterable<hstring> const& values);
        static auto CreateNameWithoutLanguage(param::hstring const& value);
        static auto CreateNameWithoutLanguageArray(param::iterable<hstring> const& values);
        static auto CreateKeyword(param::hstring const& value);
        static auto CreateKeywordArray(param::iterable<hstring> const& values);
        static auto CreateUri(llm::OS::Foundation::Uri const& value);
        static auto CreateUriArray(param::iterable<llm::OS::Foundation::Uri> const& values);
        static auto CreateUriSchema(param::hstring const& value);
        static auto CreateUriSchemaArray(param::iterable<hstring> const& values);
        static auto CreateCharset(param::hstring const& value);
        static auto CreateCharsetArray(param::iterable<hstring> const& values);
        static auto CreateNaturalLanguage(param::hstring const& value);
        static auto CreateNaturalLanguageArray(param::iterable<hstring> const& values);
        static auto CreateMimeMedia(param::hstring const& value);
        static auto CreateMimeMediaArray(param::iterable<hstring> const& values);
    };
    struct __declspec(empty_bases) IppIntegerRange : llm::OS::Devices::Printers::IIppIntegerRange
    {
        IppIntegerRange(std::nullptr_t) noexcept {}
        IppIntegerRange(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::IIppIntegerRange(ptr, take_ownership_from_abi) {}
        IppIntegerRange(int32_t start, int32_t end);
    };
    struct __declspec(empty_bases) IppPrintDevice : llm::OS::Devices::Printers::IIppPrintDevice,
        impl::require<IppPrintDevice, llm::OS::Devices::Printers::IIppPrintDevice2>
    {
        IppPrintDevice(std::nullptr_t) noexcept {}
        IppPrintDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::IIppPrintDevice(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector();
        static auto FromId(param::hstring const& deviceId);
        static auto FromPrinterName(param::hstring const& printerName);
        static auto IsIppPrinter(param::hstring const& printerName);
    };
    struct __declspec(empty_bases) IppResolution : llm::OS::Devices::Printers::IIppResolution
    {
        IppResolution(std::nullptr_t) noexcept {}
        IppResolution(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::IIppResolution(ptr, take_ownership_from_abi) {}
        IppResolution(int32_t width, int32_t height, llm::OS::Devices::Printers::IppResolutionUnit const& unit);
    };
    struct __declspec(empty_bases) IppSetAttributesResult : llm::OS::Devices::Printers::IIppSetAttributesResult
    {
        IppSetAttributesResult(std::nullptr_t) noexcept {}
        IppSetAttributesResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::IIppSetAttributesResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IppTextWithLanguage : llm::OS::Devices::Printers::IIppTextWithLanguage
    {
        IppTextWithLanguage(std::nullptr_t) noexcept {}
        IppTextWithLanguage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::IIppTextWithLanguage(ptr, take_ownership_from_abi) {}
        IppTextWithLanguage(param::hstring const& language, param::hstring const& text);
    };
    struct __declspec(empty_bases) PageConfigurationSettings : llm::OS::Devices::Printers::IPageConfigurationSettings
    {
        PageConfigurationSettings(std::nullptr_t) noexcept {}
        PageConfigurationSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::IPageConfigurationSettings(ptr, take_ownership_from_abi) {}
        PageConfigurationSettings();
    };
    struct __declspec(empty_bases) PdlPassthroughProvider : llm::OS::Devices::Printers::IPdlPassthroughProvider
    {
        PdlPassthroughProvider(std::nullptr_t) noexcept {}
        PdlPassthroughProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::IPdlPassthroughProvider(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PdlPassthroughTarget : llm::OS::Devices::Printers::IPdlPassthroughTarget,
        impl::require<PdlPassthroughTarget, llm::OS::Foundation::IClosable>
    {
        PdlPassthroughTarget(std::nullptr_t) noexcept {}
        PdlPassthroughTarget(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::IPdlPassthroughTarget(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Print3DDevice : llm::OS::Devices::Printers::IPrint3DDevice
    {
        Print3DDevice(std::nullptr_t) noexcept {}
        Print3DDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::IPrint3DDevice(ptr, take_ownership_from_abi) {}
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector();
    };
    struct __declspec(empty_bases) PrintSchema : llm::OS::Devices::Printers::IPrintSchema
    {
        PrintSchema(std::nullptr_t) noexcept {}
        PrintSchema(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::IPrintSchema(ptr, take_ownership_from_abi) {}
    };
}
#endif
